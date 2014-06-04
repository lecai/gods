//
//  GString.cpp
//  gods
//
//  Created by eacan  on 14-6-2.
//
//

#include "GString.h"
#include <stdio.h>
#include <stdarg.h>

const unsigned int MAX_FORMAT_STR_BUFF = 2048;

GString & GString::operator=(const char *lpszStr){
    _str.assign(lpszStr);
    return *this;
}

int GString::format(const char *format, ...) {
    int nRV = 0;
    char  szBuf[MAX_FORMAT_STR_BUFF] = {0x00,};

    va_list vaList;

    memset(szBuf, 0x00, sizeof(szBuf));
    va_start(vaList, format);
    nRV = vsprintf(szBuf, format, vaList);
    va_end(vaList);
    if (nRV>0)
        _str.assign(szBuf);
    else
        _str.clear();
    return nRV;
}

