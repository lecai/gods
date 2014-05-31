//
// Created by lecai on 14-5-29 上午11:40.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
// 随机数 生成类



#ifndef __GRandomGenerator_H_
#define __GRandomGenerator_H_

/**
* @brief 一个伪随机数生成器. 性能不咋滴 但是可以生成32位随机数(大部分是生成15位随机数)
*
*
*/
class GRandomGenerator {
public:
    GRandomGenerator(void);
    GRandomGenerator(unsigned int seed);
    GRandomGenerator &operator=(GRandomGenerator &random);

    virtual ~GRandomGenerator(void);

public:
    unsigned int Generate();
    void Reset();

protected:
    enum {
        TABLE_SIZE = 250,
    };
    void Init(unsigned int seed);
    void GenerateSeeds();
    unsigned int GenerateSimple();

private:
    unsigned int _nState;
    int          _nIndex1;
    int          _nIndex2;
    unsigned int _seed;
    unsigned int _table[TABLE_SIZE];

};


#endif //__GRandomGenerator_H_
