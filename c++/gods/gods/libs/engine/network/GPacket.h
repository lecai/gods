//
// Created by lecai on 14-5-30 上午1:16.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GPacket_H_
#define __GPacket_H_

struct stPacketHeader{
    unsigned short bEncrypt:1; //特殊包头加密
    unsigned short wPacketLen:15;
    unsigned char  bySequence;
    unsigned char  byCheckSum;
};

typedef stPacketHeader PACKETHEADER , *LPPACKETHEADER;

struct stPacketData{
    stPacketData(){}
    stPacketData(unsigned short opcode):wOpCode(opcode){}
    unsigned short wOpCode;
};
typedef stPacketData PACKETDATA,*LPPACKETDATA;

const int PACKET_LIMIT_SIZE = 0x7FFF;//剔除加密的1个bit
const int PACKET_HEAD_SIZE = (sizeof(PACKETHEADER));
const unsigned char PACKET_MAX_SEQUENCE = 0xFF ;
const int PACKET_MAX_SIZE = 4096;  //常用最大数据包

class GPacket {
public:
public:
private:
};




#endif //__GPacket_H_
