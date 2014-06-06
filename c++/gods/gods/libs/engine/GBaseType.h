//
// Created by lecai on 14-6-6 上午9:41.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GBaseType_H_
#define __GBaseType_H_

#define BEGIN_NAMESPACE(NAME)  namespace NAME {
#define END_NAMESPACE(NAME)    }using namespace NAME;


#define USE_NAMESPACE(NAME)  using namespace NAME;
#define USE_NAMESPACE_ELEMENT(NAME,ELEMENT) using NAME::ELEMENT;
#define USE_STD_ELEMENT(ELEMENT)  using std::ELEMENT;

#define down_cast    reinterpret_cast
#define up_cast      reinterpret_cast

BEGIN_NAMESPACE(base)

typedef signed char  Int8;
typedef unsigned char UInt8;
typedef signed short			Int16;
typedef unsigned short			UInt16;
typedef signed long				Int32;
typedef unsigned long			UInt32;

typedef float					Float32;
typedef double					Float64;

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;

END_NAMESPACE(base)

#endif //__GBaseType_H_
