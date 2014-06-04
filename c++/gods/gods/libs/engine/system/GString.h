//
//  GString.h
//  gods
//
//  Created by eacan  on 14-6-2.
//
//

#ifndef __gods__GString__
#define __gods__GString__

#include <iostream>
#include <string>

class GString{
public:
    GString(){}
    GString(const char *lpszStr):_str(lpszStr){}
public:
    std::string & getString(void){return _str;}
    GString &operator=(const char *lpszStr);
    
    int format(const char *format,...);
    const char *c_str(void) const {return _str.c_str();}
    void clear(void){_str.clear();}
    
    bool operator<(const GString &right){
        if (_str<right._str) return true;
        else return false;
    }
private:
    std::string _str;
};

#endif /* defined(__gods__GString__) */
