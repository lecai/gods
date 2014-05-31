//
// Created by lecai on 14-5-30 下午12:51.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GCircularQueue_H_
#define __GCircularQueue_H_

template <class TYPE>
class GCircularQueue {
public:
    GCircularQueue(){

    }

    virtual ~GCircularQueue(){

    }

public:
    bool Create(int queueSize,int extraSize);
    void Destroy();

public:
    bool Realloc(int queueSize,int extraSize){
        return Create(queueSize,extraSize);
    }

    void Clear();

    int  GetQueueSize(){
        return QUEUE_SIZE;
    }

    int GetExtraSize(){
        return EXTRA_SIZE;
    }

    int GetTotalSize(){
        return QUEUE_SIZE+EXTRA_SIZE;
    }

public:
    int GetFreeSize(){
        return GetQueueSize()-GetCurSize();
    }

    int GetCurSize();



private:
    int QUEUE_SIZE;
    int EXTRA_SIZE;
    int _nPushPos;
    int _nPopPos;
    TYPE *_queueBuffer;
    int _nLoopCount;
};


#endif //__GCircularQueue_H_
