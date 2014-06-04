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

inline void GLinkList::insertAfter(GLinkObject *baseObject, GLinkObject *linkObject) {
    if (!baseObject)
    {
        append(baseObject);
    } else{
        GLinkObject *next = baseObject->getNext();
        linkObject->setPrev(baseObject);
        linkObject->setNext(next);
        baseObject->setNext(linkObject);
        if (!next)
        {
            _tail = linkObject;
        } else{
            next->setPrev(linkObject);
        }

        ++_count;
        if (_count > _maxCount)
        {
            _maxCount = _count;
        }
    }
}

inline void GLinkList::remove(GLinkObject *linkObject) {
    GLinkObject *prev = linkObject->getPrev();
    GLinkObject *next = linkObject->getNext();

    if (next)
    {
        next->setPrev(prev);
    } else{
        _tail = prev;
    }

    if (prev)
    {
        prev->setNext(next);
    } else{
        _head = next;
    }

    linkObject->setPrev(NULL);
    linkObject->setNext(NULL);

    --_count;
}

inline void GLinkList::removeAll() {
    while (_count > 0)
    {
        remove(_head);
    }
}

inline bool GLinkList::find(GLinkObject *baseObject) {
    GLinkObject *object = _head;
    while (object)
    {
        if (object == baseObject)
        {
            return true;
        }
        object = object->getNext();
    }
    return true;
}

inline GLinkObject* GLinkList::popFront() {
    GLinkObject *linkObject = _head;
    if (linkObject)
    {
        remove(linkObject);
    }
    return linkObject;
}

inline GLinkObject* GLinkList::popBack() {
    GLinkObject *linkObject = _tail;
    if (linkObject)
    {
        remove(linkObject);
    }
    return linkObject;
}

inline GLinkObject* GLinkList::pop(bool front) {
    return front? popFront(): popBack();
}

inline void GLinkList::push(GLinkObject *linkObject, bool front) {
    front ? prePrepend(linkObject):append(linkObject);
}


