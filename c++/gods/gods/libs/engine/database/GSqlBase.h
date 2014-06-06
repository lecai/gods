//
// Created by lecai on 14-6-1 上午2:38.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GSqlBase_H_
#define __GSqlBase_H_

#include "mysql.h"
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
namespace mysql{
    enum State{
       IDLE = 0,
       USING = 1,
    };
    class Connections;
    class Connection{
    public:
        State _state;
        int ping(){
            return mysql_ping(<#(MYSQL*)mysql#>)
        }
        MYSQL *_mysql;
        Connections *_connections;
        Connection(Connections *connections):_connections(connections){
            _connections = NULL;
            _state = IDLE;
            _mysql = NULL;
        }

        void close(){
            mysql_close(_mysql);
        }

        void setState(State state){
            this->_state = state;
        }
    };
    class Connections{
    public:
        Connection *getConnection();
        void putConnect(Connection *connection);

    private:
        std::string _host;
        std::string _port;
        std::string _username;
        std::string _password;
        std::string _dbname;
        std::list<Connection*> _conns;
    };
    class FieldInfo{
    public:
        FieldInfo(){
            _type = -1;
        }
        FieldInfo(std::string &name,int type);
        FieldInfo(std::string &name,std::string &value);
        template <int size>
        FieldInfo(const std::string &name, char (&a)[size]){
            this->_name = name;
        }
        FieldInfo(const std::string &name,std::vector<char> &buffer);
        std::string getDesc();
        bool equal(FieldInfo &info);

    private:
        std::string _name;
        int _type;
    };
    class EachFieldInfo{
    public:
        virtual void callback(FieldInfo &field){}
        virtual void end(){}
        virtual void begin(){}
    };
    class TableInfo{
    public:
        std::string name;
        std::vector<FieldInfo> fields;
        FieldInfo *findField(const std::string &fieldName);
        void execAll(EachFieldInfo *exec);
    };
    class DB{
    public:
        bool init(const char *host, const char *dbname, const char *usernam, const char *password);
        bool execSql(const std::string &sql);

        TableInfo *getTable(const std::string &name);
        
    };



};
class GSqlBase {
    MYSQL_

};


#endif //__GSqlBase_H_
