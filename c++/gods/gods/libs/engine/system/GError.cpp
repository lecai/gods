//
// Created by lecai on 14-6-5 上午10:19.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "GError.h"

#ifdef G_DEFINE_ERROR
#undef G_DEFINE_ERROR
#define G_DEFINE_ERROR(x) #x,
#endif

char * g_error_string[MAX_G_ERROR-G_ERR_BEGIN]=
{
    "G_ERR_BEGIN",

#include "GErrorCodes.h"
};

const char *GetGErrorString(int errorCode)
{
    if (errorCode >= MAX_G_ERROR)
        return "G Error message not found";
    return g_error_string[errorCode-G_ERR_BEGIN];
}

const unsigned int MAX_ERR_STR_BUF = 256;

void GGetErrorString(GString &stError,int errorCode){
    if (errorCode >= G_ERR_BEGIN)
    {
        stError = GetGErrorString(errorCode);
    } else
    {
        char szBuf[MAX_ERR_STR_BUF] = {0x00,};

    }
}
const char *GGetErrorMessage(int errorCode){
    if (errorCode >= G_ERR_BEGIN)
    {
        return const_cast<char *>(GetGErrorString(errorCode));
    } else
    {
        static char szBuf[MAX_ERR_STR_BUF] = { 0x00, };
        return szBuf;
    }
}