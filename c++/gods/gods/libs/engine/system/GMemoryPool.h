//
// Created by lecai on 14-6-4 上午9:45.
//
// To change the template use AppCode | Preferences | File Templates.
// 对象内存池 (静态 与 动态)



#ifndef __GMemoryPool_H_
#define __GMemoryPool_H_

#include <deque>
#include "thread.h"

template <class TYPE>
class GMemeoryPool_Dynamic{
public:
    GMemeoryPool_Dynamic(int reserved = 0);
    virtual ~GMemeoryPool_Dynamic();

public:
    void destroy();
    TYPE *alloc();
    void free(TYPE *t);
    int getTotalCount();

private:
    void init();
    bool reserve(int count);
private:
    typedef std::deque<TYPE*> LIST;
    typedef typename LIST::iterator LIST_ITER;

    LIST  _store;
    int   _totalCount; //内存生成数
    int   _reserved; //预留的数量
};

template <class TYPE>
inline GMemeoryPool_Dynamic<TYPE>::GMemeoryPool_Dynamic(int reserved)
:_reserved(reserved),_totalCount(0){
    if(reserved>0)
    {
        reserve(_reserved);
    }
}

template <class TYPE>
inline void GMemeoryPool_Dynamic<TYPE>::destroy() {
    LIST_ITER  iter = _store.begin();
    while (iter != _store.end())
    {
        free(*iter);
        iter = _store.erase(iter);
        _totalCount--;
    }
}

template <class TYPE>
inline bool GMemeoryPool_Dynamic<TYPE>::reserve(int count) {
    for(int i=0;i<count;i++)
    {
        TYPE *pObject = (TYPE*)malloc(sizeof(TYPE));
        if(NULL == pObject)
        {
            destroy();
            return false;
        }
        _store.push_back(pObject);
        _totalCount++;
    }
    return true;
}

template <class TYPE>
inline TYPE * GMemeoryPool_Dynamic<TYPE>::alloc() {
    TYPE *pObject = NULL;
    if(true == _store.empty())
    {
        pObject = (TYPE*)malloc(sizeof(TYPE));
        if(NULL == pObject)
        {
            return NULL;
        }
        _totalCount++;
    } else{
        pObject = *_store.begin();
        _store.pop_front();
    }
    return pObject;
}

template <class TYPE>
inline void GMemeoryPool_Dynamic<TYPE>::free(TYPE *t) {
    _store.push_front(t);
}

/**********************************************************
* 动态对象内存池 宏定义
*************************************************************/
#define DECLARE_DYNAMIC_MEMORYPOOL(classname) \
public:                                           \
    void * operator new(size_t allocBlock);       \
    void operator delete(void *pMem);             \
private:                                          \
    static GMemeoryPool_Dynamic<classname> _memoryPool;

#define DEFINE_DYNAMIC_MEMORYPOOL(classname,resverse) \
GMemeoryPool_Dynamic<classname> classname::_memoryPool(resverse)\
void *classname::operator new(size_t allocBlock)                \
{                                                               \
    (void) allocBlock;											\
    classname * pMem = _memoryPool.alloc();                     \
    return pMem;                                                \
}                                                               \

#ifdef __DONOT_USE_MEMORYPOOL__
	#undef DECLARE_DYNAMIC_MEMORYPOOL
	#define DECLARE_DYNAMIC_MEMORYPOOL(classname)

	#undef DEFINE_DYNAMIC_MEMORYPOOL
	#define DEFINE_DYNAMIC_MEMORYPOOL(classname, reserve)
#endif

//-----------------------------------------------------------------------------------
// 动态对象内存池 宏定义 ( 线程安全 )
//-----------------------------------------------------------------------------------
#define DECLARE_DYNAMIC_MEMORYPOOL_THREADSAFE(classname)					\
public:																		\
	void * operator new( size_t stAllocationBlock );						\
	void operator delete( void * pMem );									\
private:																	\
	static CNtlMutex __m_poolMutex__;										\
	static CNtlMemoryPool_Dynamic<classname> __m_memoryPool__;


#define DEFINE_DYNAMIC_MEMORYPOOL_THREADSAFE(classname, reserve)			\
	CNtlMutex classname::__m_poolMutex__;									\
	CNtlMemoryPool_Dynamic<classname> classname::__m_memoryPool__(reserve); \
	void * classname::operator new( size_t stAllocationBlock )				\
	{																		\
		(void) stAllocationBlock;											\
		__m_poolMutex__.Lock();												\
		classname * pMem = __m_memoryPool__.Alloc();						\
		__m_poolMutex__.Unlock();											\
		return pMem;														\
	}																		\
																			\
	void classname::operator delete( void * pMem )							\
	{																		\
		__m_poolMutex__.Lock();												\
		__m_memoryPool__.Free((classname*)pMem);							\
		__m_poolMutex__.Unlock();											\
	}

#ifdef __DONOT_USE_MEMORYPOOL__
	#undef DECLARE_DYNAMIC_MEMORYPOOL_THREADSAFE
	#define DECLARE_DYNAMIC_MEMORYPOOL_THREADSAFE(classname)

	#undef DEFINE_DYNAMIC_MEMORYPOOL_THREADSAFE
	#define DEFINE_DYNAMIC_MEMORYPOOL_THREADSAFE(classname, reserve)
#endif

//-----------------------------------------------------------------------------------
// TODO:: 静态对象内存池
//-----------------------------------------------------------------------------------

#endif //__GMemoryPool_H_
