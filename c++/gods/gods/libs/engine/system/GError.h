//
// Created by lecai on 14-6-5 上午10:19.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GError_H_
#define __GError_H_

#include "GString.h"

#define G_DEFINE_ERROR(x)   x,

enum {
    G_ERR_BEGIN = 100000,

#include "GErrorCodes.h"

    MAX_G_ERROR

};
void GGetErrorString(GString &stError,int errorCode);
const char *GGetErrorMessage(int errorCode);



#endif //__GError_H_
