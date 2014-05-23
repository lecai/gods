//
// Created by eacan  on 14-5-23 上午11:33.
//
// To change the template use AppCode | Preferences | File Templates.
// @brief 定义none copy 类 ,使所有子类禁用拷贝构造函数的
//



#ifndef __LCantCopy_H_
#define __LCantCopy_H_


class GCantCopy {
protected:
    /**
    * @brief 缺省构造函数
    *
    */
    GCantCopy(){};

    /**
    * @brief 缺省析构函数
    *
    */
    ~GCantCopy(){};
private:
    /**
    *@brief 拷贝构造函数 ,没有实现,禁止掉了
    */
    GCantCopy(const GCantCopy&);

    /**
    *@brief 赋值操作符号 ,没有实现,禁止掉了
    */
    const GCantCopy & operator=(const GCantCopy &);
};


#endif //__LCantCopy_H_
