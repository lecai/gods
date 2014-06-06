//
// Created by lecai on 14-6-6 下午12:30.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __LPacket_H_
#define __LPacket_H_

/**
*
* @brief
*
* 1) 命名 Op-code
*   使用字母,区分消息分组
*   U - User(Client)
*   A - Account Server
*   G - Game Server
*   C - Chat Server
*   D - DB Server
*   L - Log Server
*   M - Monitoring Server
*   Ch- Charater Server
*
*   ex:如果一个消息包要从游戏服务器发送到DB服务器 ,它的消息包Op-code 则为 'OpGTD'
*
*
*
*
*
*
*
*
*
*
*
*/

class LPacket {

};


#endif //__LPacket_H_
