//
// Created by lecai on 14-5-25 下午11:17.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
// 循环队列



#ifndef __GCircularQueue_H_
#define __GCircularQueue_H_

template<class TYPE>
class GCircularQueue {
public:
    GCircularQueue()
    {

    }
    virtual ~GCircularQueue(){}

public:
    bool create(int queueSize,int extraSize);
    void destroy();

public:
    bool reAlloc(int queueSize,int extraSize);
    void clear();
    int getQueueSize(){return QUEUE_SIZE;}
    int getQueueExtraSize(){return EXTRA_SIZE;}
    int getQueueTotalSize(){return getQueueSize() + getQueueExtraSize();}

public:
    int getFreeSize(){return getQueueSize()-getCurSize();}
    int getLinerFreeSize(){return getQueueTotalSize()-getPushPos();}
    int getCurSize();
    int getPushAvailableSize();
    int getWorkRemainSize();
    int getQueueLoopCount(){return _loopCount;}

    int getPushPos(){return _pushPos;}
    int getPopPos(){return _popPos;}
    int getWorkPos(){return _workPos;}
    TYPE *getQueuePtr(int pos);
    TYPE *getQueuePushPtr(){return getQueuePtr(getPushPos());}
    TYPE *getQueuePopPtr(){return getQueuePtr(getPopPos());}
    TYPE *getQueueWorkPtr(){return getQueuePtr(getWorkPos());}
public:
    bool     isFull(){return getCurSize()== getQueueSize();}
protected:
    void     init();
    TYPE*    getQueueBufferPtr(){return _queueBuffer;}
    TYPE*    getQueueExtraPtr(){return &_queueBuffer[QUEUE_SIZE];}
private:
    int      QUEUE_SIZE;
    int      EXTRA_SIZE;
    int      _pushPos;
    int      _popPos;
    int      _workPos;
    TYPE*    _queueBuffer;
    int      _loopCount;

};


#endif //__GCircularQueue_H_
