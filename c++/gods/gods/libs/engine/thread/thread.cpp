//
//  thread.cpp
//  luanet
//
//  Created by eacan  on 14-2-17.
//
//

#include "thread.h"
#include <signal.h>
#include <pthread.h>
#include <algorithm>
#include <unistd.h>

namespace thread
{
    Mutex::Mutex()
    {
        pthread_mutex_init(&m_hMutex, NULL);
    }
    
    Mutex::~Mutex()
    {
        pthread_mutex_destroy(&m_hMutex);
    }
    inline void Mutex::lock()
    {
        pthread_mutex_lock(&m_hMutex);
    }
    inline void Mutex::unlock()
    {
        pthread_mutex_unlock(&m_hMutex);
    }
    
    /*
     * RWLock
     */
    RWLock::RWLock():rd_count(0),wr_count(0)
    {
        pthread_rwlock_init(&m_hMutex, NULL);
    }
    RWLock::~RWLock()
    {
        pthread_rwlock_destroy(&m_hMutex);
    }
    inline void RWLock::rdlock()
    {
        pthread_rwlock_rdlock(&m_hMutex);
        ++rd_count;
    }
    inline void RWLock::wrlock()
    {
        pthread_rwlock_wrlock(&m_hMutex);
        ++wr_count;
        ++rd_count;
    }
    inline void RWLock::unlock()
    {
        pthread_rwlock_destroy(&m_hMutex);
        --rd_count;
    }
    
    /*
     * Cond
     */
    Cond::Cond()
    {
        ::pthread_cond_init(&m_hEvent, NULL);
    }
    Cond::~Cond()
    {
        ::pthread_cond_destroy(&m_hEvent);
    }
    void Cond::broadcast()
    {
        ::pthread_cond_broadcast(&m_hEvent);
    }
    void Cond::signal()
    {
        ::pthread_cond_signal(&m_hEvent);
    }
    void Cond::wait(Mutex &m)
    {
        ::pthread_cond_wait(&m_hEvent, &m.m_hMutex);
    }
    /***************************操作包裹类***************************************/
    /*
     * Mutex_scope_lock
     */
    Mutex_scope_lock::Mutex_scope_lock(Mutex &m):m_Mutex(m)
    {
        m_Mutex.lock();
    }
    Mutex_scope_lock::~Mutex_scope_lock()
    {
        m_Mutex.unlock();
    }
    /*
     * Mutex_scope_rdlock
     */
    RWLock_scope_rdlock::RWLock_scope_rdlock(RWLock &m):m_RwLock(m)
    {
        m_RwLock.rdlock();
    }
    RWLock_scope_rdlock::~RWLock_scope_rdlock()
    {
        m_RwLock.unlock();
    }
    /*
     * RWLock_scope_wrlock
     */
    RWLock_scope_wrlock::RWLock_scope_wrlock(RWLock &m):m_RwLock(m)
    {
        m_RwLock.wrlock();
    }
    RWLock_scope_wrlock::~RWLock_scope_wrlock()
    {
        m_RwLock.unlock();
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Thread::Thread(const std::string &name,bool joinable):threadName(name),alive(false),complete(false),joinable(joinable)
    {
        m_hThread = 0;
    }
    Thread::~Thread()
    {
        
    }
    void Thread::sleep(const long sec)
    {
        ::sleep(sec*1000);
    }
    void Thread::msleep(const long msec)
    {
        ::sleep(msec);
    }
    void Thread::usleep(const long usec)
    {
        ::sleep(usec/1000);
    }
    /*
     *检查线程是否joinable
     *@return joinable
     */
    const bool Thread::isJoinable() const
    {
        return joinable;
    }
    
    /*
     *检查线程是否运行
     *@return alive
     */
    const bool Thread::isAlive() const
    {
        return alive;
    }
    /*
     *主动结束线程
     *只是设置标志 当线程run 主回调循环检查这个标志,如果这标志已经设置,则退出线程
     */
    void Thread::final()
    {
        complete = true;
    }
    
    const bool Thread::isFinal() const
    {
        return complete;
    }
    
    const std::string & Thread::getThreadName() const
    {
        return threadName;
    }
    void * Thread::threadFunc(void *arg)
    {
        Thread *thread = (Thread*)arg;
        thread->m_Lock.lock();
        thread->alive=true;
        thread->m_Cond.broadcast();
        thread->m_Lock.unlock();
        
        //设置线程信号处理句柄
        sigset_t sig_mask;
        sigfillset(&sig_mask);
        pthread_sigmask(SIG_SETMASK, &sig_mask, NULL);
        
        //运行线程的主回调函数
        thread->run();
        
        thread->m_Lock.lock();
        thread->alive=false;
        thread->m_Cond.broadcast();
        thread->m_Lock.unlock();
        
        //如何是非joinable 需要回收线程资源
        if (!thread->isJoinable())
        {
            thread->m_Lock.lock();
            while (thread->alive)
            {
                thread->m_Cond.wait(thread->m_Lock);
            }
            thread->m_Lock.unlock();
            delete thread;
        }
        pthread_exit(NULL);
    }
    
    /*
     *创建线程 启动线程
     *@return 线程启动是否成功
     */
    bool Thread::start()
    {
        //线程已经创建,直接返回
        if (alive)
        {
            return true;
        }
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        if (!joinable)
        {
            pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        }
        if (0 != pthread_create(&m_hThread, &attr, threadFunc, this))
        {
            return false;
        }
        pthread_attr_destroy(&attr);
        
        //由于设置为分离线程 防止由于线程运行速度过快 pthread_create函数返回之前就终止
        m_Lock.lock();
        while (!alive)
        {
            m_Cond.wait(m_Lock);
        }
        m_Lock.unlock();
        return true;
    }
    
    /*
     *等待一个线程结束 释放占用的资源
     */
    void Thread::join()
    {
        if (0 != m_hThread && joinable)
        {
            ::pthread_join(m_hThread, NULL);
            m_hThread = 0;
            m_Lock.lock();
            while (alive) {
                m_Cond.wait(m_Lock);
            }
            m_Lock.unlock();
        }
    }
    
    /*
     * ThreadGroup
     */
    ThreadGroup::ThreadGroup():vts(),rwlock()
    {
    }
    
    ThreadGroup::~ThreadGroup()
    {
        joinAll();
    }
    
    /**
     * @brief 添加一个线程到分组中
     * @param thread 待添加的线程
     */
    void ThreadGroup::add(Thread *thread)
    {
        RWLock_scope_wrlock scope_wrlock(rwlock);
        Container::iterator it = std::find(vts.begin(), vts.end(), thread);
        if (it == vts.end()) vts.push_back(thread);
    }
    
    /**
     *@brief 按照index下标获取线程
     *@param index 下标编号
     *
     */
    Thread * ThreadGroup::getByIndex(const Container::size_type index)
    {
        RWLock_scope_rdlock scope_rdlock(rwlock);
        if (index>=vts.size()) return NULL;
        else return vts[index];
    }
    
    /**
     *@brief 重载[] 运算符,按照index下标获取线程
     *@param index 下标编号
     *@return 线程
     */
    Thread *ThreadGroup::operator[](const Container::size_type index)
    {
        RWLock_scope_rdlock scope_rdlock(rwlock);
		if (index >= vts.size())
			return NULL;
		else
			return vts[index];
    }
    
    /*
     *@brief 等待分组中的所有线程结束
     */
    void ThreadGroup::joinAll()
    {
        RWLock_scope_rdlock scope_wrlock(rwlock);
        while (!vts.empty())
        {
            Thread *pThread = vts.back();
            vts.pop_back();
            if (pThread)
            {
                pThread->final();
                pThread->join();
                delete pThread;
            }
        }
    }
    
    
    
};
