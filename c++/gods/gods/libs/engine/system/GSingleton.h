//
// Created by lecai on 14-5-29 下午9:59.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GSingleton_H_
#define __GSingleton_H_

template <class TYPE>
class GSingleton {
public:
    GSingleton(){
        _pInstance = static_cast<TYPE*>(this);
    }

    virtual ~GSingleton(){
        _pInstance = NULL;
    }

    static TYPE *GetInstance(void){
        return _pInstance;
    }
private:
    static TYPE *_pInstance;
};
template <class TYPE> TYPE * GSingleton<TYPE>::_pInstance = NULL;


#endif //__GSingleton_H_
