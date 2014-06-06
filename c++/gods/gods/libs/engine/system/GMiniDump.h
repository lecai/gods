//
// Created by lecai on 14-5-29 下午9:34.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GMiniDump_H_
#define __GMiniDump_H_


class GMiniDump {
public:
    GMiniDump();
    virtual ~GMiniDump();

public:
    static bool start();
    static void stop();
    static void snapshot();

private:
    static char _dumpPath[]

};


#endif //__GMiniDump_H_
