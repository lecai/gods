//
// Created by lecai on 14-6-1 上午3:25.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include <sys/_types/_null.h>
#include <sys/_types.h>
#include "GLinkList.h"

//后置加 类似队列
inline void GLinkList::append(GLinkObject *linkObject) {
    if(!_head)
    {
        _head = linkObject;
    }
    linkObject->setPrev(_tail);
    if(_tail)
    {
        _tail->setNext(linkObject);
    }
    _tail = linkObject;
    linkObject->setNext(NULL);

    ++_count;
    if (_count > _maxCount)
    {
        _maxCount = _count;
    }
}

//前置加 类似栈
inline void GLinkList::prePrepend(GLinkObject *linkObject) {
    if (!_tail)
    {
        _tail = linkObject;
    }
    linkObject->setNext(_head);
    if (_head)
    {
        _head->setPrev(linkObject);
    }
    _head = linkObject;
    linkObject->setPrev(NULL);

    ++_count;
    if (_count > _maxCount)
    {
        _maxCount = _count;
    }
}

inline void GLinkList::insertBefore(GLinkObject *baseObject, GLinkObject *linkObject) {
    if (!baseObject)
    {
        prePrepend(linkObject);
    } else{
        GLinkObject *prev = baseObject->getPrev();
        linkObject->setNext(baseObject);
        linkObject->setPrev(prev);
        baseObject->setPrev(linkObject);
        if (!prev)
        {
            _head = linkObject;
        } else{
            prev->setNext(linkObject);
        }

        ++_count;
        if (_count > _maxCount)
        {
            _maxCount = _count;
        }
    }
}


