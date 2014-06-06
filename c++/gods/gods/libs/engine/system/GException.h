//
// Created by lecai on 14-6-5 上午9:47.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GException_H_
#define __GException_H_

#include "GString.h"
#include <stdio.h>

#define THROW_EXCEPTION(s) throw GException(__FILE__, __LINE__, __FUNCTION__, s)

class GException {
public:
public:
    GException(const char *filename,int line, const char *func, const char *strWhat)
    :_strFile(filename),_line(line), _strFunc(func), _strWhat(strWhat) {};

    virtual ~GException(){}

    virtual void dump(FILE *fp = stderr){
        fprintf(fp, "EXCEPTION :[%s] in file %s [Line:%d] [Func:%s]", getWhat(), getFile(), getLine(), getFunc());
    }

    const char * getFile() const {return _strFile->c_str();}
    int          getLine() const {return _line;}
    const char * getFunc() const {return _strFunc->c_str();}
    const char * getWhat() const {return _strWhat->c_str();}

protected:
    GString *_strFile;
    int     _line;
    GString *_strFunc;
    GString *_strWhat;
};


#endif //__GException_H_
