//
// Created by lecai on 14-6-1 上午3:25.
//
// To change the template use AppCode | Preferences | File Templates.
// 链表



#ifndef __GLinkList_H_
#define __GLinkList_H_

class GLinkObject{
public:
    GLinkObject();
    virtual ~GLinkObject(){

    }

public:
    GLinkObject *getNext(){
        return _next;
    }
    void setNext(GLinkObject *next){
        _next = next;
    }

    GLinkObject *getPrev(){
        return _prev;
    }

    void setPrev(GLinkObject *prev){
        _prev = prev;
    }

private:
    GLinkObject *_prev;
    GLinkObject *_next;
};

class GLinkList {
public:
    GLinkList(void);
    virtual ~GLinkList(void){

    }

public:
    bool isEmpty(){
        return _count == 0;
    }

    int getCount(){
        return _count;
    }

    int getMaxCount(){
        return _maxCount;
    }

    GLinkObject *getFirst(){
        return _head;
    }

    GLinkObject *getLast(){
        return _tail;
    }

public:
    void append(GLinkObject *linkObject);
    void prePrepend(GLinkObject *linkObject);
    void insertBefore(GLinkObject *baseObject,GLinkObject *linkObject);
    void insertAfter(GLinkObject *baseObject,GLinkObject *linkObject);
    void remove(GLinkObject *linkObject);
    void removeAll();
    bool find(GLinkObject *baseObject);
    GLinkObject *pop(bool front = false);
    void push(GLinkObject *linkObject, bool front = true);
    GLinkObject * popFront();
    GLinkObject * popBack();
    void pushBack(GLinkObject *linkObject){
        append(linkObject);
    }
    void pushFront(GLinkObject *linkObject){
        prePrepend(linkObject);
    }

private:
    GLinkObject *_head;
    GLinkObject *_tail;
    int         _count;
    int         _maxCount;
};


#endif //__GLinkList_H_
