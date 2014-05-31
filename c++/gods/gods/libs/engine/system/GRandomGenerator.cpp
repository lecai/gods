//
// Created by lecai on 14-5-29 上午11:40.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
// 伪随机数 生成器


#include <stdlib.h>
#include <string.h>
#include "GRandomGenerator.h"

GRandomGenerator::GRandomGenerator(void) {
}

GRandomGenerator::~GRandomGenerator(void) {

}
GRandomGenerator::GRandomGenerator(unsigned int seed) {
    Init(seed);
}

GRandomGenerator& GRandomGenerator::operator = (GRandomGenerator &random) {
    _seed = random._seed;
    _nState = random._nState;
    _nIndex1 = random._nIndex1;
    _nIndex2 = random._nIndex2;
    memcpy(_table,random._table, sizeof(unsigned int)*TABLE_SIZE);
    return *this;
}

void GRandomGenerator::Init(unsigned int seed) {
    _seed = seed;
    _nState = seed;
    GenerateSeeds();
}

void GRandomGenerator::Reset() {
    _nState = _seed;
    GenerateSeeds();
}

unsigned int GRandomGenerator::Generate() {
    unsigned int retval = (_table[_nIndex1] ^= _table[_nIndex2]);

    _nIndex1++;
    if (_nIndex1 == TABLE_SIZE)
        _nIndex1 = 0;

    _nIndex2++;
    if (_nIndex2 == TABLE_SIZE)
        _nIndex2 = 0;


    return retval;
}

void GRandomGenerator::GenerateSeeds() {
    int n;
    unsigned int msk, bit;

    _nIndex1 = 0;
    _nIndex2 = 103;

    for ( n = TABLE_SIZE - 1; n >= 0; n-- )
        _table[n] = GenerateSimple();

    for ( n = 3, msk = 0xffffffff, bit = 0x80000000; bit; n += 7 )
    {
        _table[n] = (_table[n] & msk) | bit;
        msk >>= 1;
        bit >>= 1;
    }
}

unsigned int GRandomGenerator::GenerateSimple() {
    /* IL_Shift32Random from Inner Loops book */
    unsigned int n, bit, temp;
    temp = _nState;

    for (n=0; n < 32; n++)
    {
        bit = ((temp >> 0) ^ (temp >> 1) ^ (temp >> 2) ^ (temp >> 3) ^ (temp >> 5) ^ (temp >> 7)) & 1;
        temp = (((temp >> 1) | (temp << 31)) & ~1) | bit;
    }

    _nState = temp;

    return _nState;
}


