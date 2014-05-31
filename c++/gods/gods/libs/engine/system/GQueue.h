//
// Created by lecai on 14-6-1 上午2:45.
//
// To change the template use AppCode | Preferences | File Templates.
// 队列



#ifndef __GQueue_H_
#define __GQueue_H_

#include <deque>
#include "thread.h"

template <class TYPE>
class GQueue {
public:
    GQueue();
    virtual ~GQueue();

    
public:
    TYPE    pop();
    bool    push(TYPE typeObject, bool bFront = false);
    TYPE    peek();
    void    clear();

    unsigned long getMaxUsedSize(){
        return  _maxUseSize;
    }
    unsigned long getSize(){
        return (unsigned long)_queue.size();
    }
    bool    isEmpty(){
        return _queue.empty();
    }

private:
    std::deque<TYPE> _queue;
    thread::Mutex    _mutex;
    unsigned long    _maxUseSize;
    
};

template <class TYPE>
inline GQueue<TYPE>::GQueue() {
    _maxUseSize = 0;
}

template <class TYPE>
inline TYPE GQueue<TYPE>::pop() {
    TYPE typeObject;
    _mutex.lock();
    if(false == _queue.empty())
    {
        typeObject = _queue.front();
        _queue.pop_front();
    } else{
        //重置指针
        memset(&typeObject,0, sizeof(TYPE));
    }
    _mutex.unlock();
    return typeObject;
}

template <class TYPE>
inline bool GQueue<TYPE>::push(TYPE typeObject, bool bFront) {
    _mutex.lock();
    if(getSize() > _maxUseSize)
    {
        _maxUseSize = getSize();
    }
    _mutex.unlock();
    return true;
}

template <class TYPE>
inline TYPE GQueue<TYPE>::peek() {
    TYPE typeObject;
    _mutex.lock();
    if(false == _queue.empty())
    {
        typeObject = _queue.front();
    } else {
        //重置指针
        memset(&typeObject,0, sizeof(TYPE));
    }
    _mutex.unlock();
    return typeObject;
}

template <class TYPE>
inline void GQueue::clear() {
    _mutex.lock();
    if(false == _queue.empty()){
        _queue.clear();
    }
    _mutex.unlock();
}










#endif //__GQueue_H_
