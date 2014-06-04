//
// Created by lecai on 14-6-1 下午7:44.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __GPairedMap_H_
#define __GPairedMap_H_

#include <map>

template <typename TYPE1,typename TYPE2>
class GPairedMap {
public:
    GPairedMap(void);
    virtual ~GPairedMap(void){}

public:
    bool add(TYPE1 val1,TYPE2 val2){
        
    }
    void removeWithFirst(TYPE1 val1){
        
    }
    void removeWithSecond(TYPE2 val2){
        FIRST_LIST_ITER iter= _secondList.find(val2);
        if( it != _firsetList.end() )
		{
			_firsetList.erase( it->second );
            
			_secondList.erase( it );
		}
    }
    unsigned long getCount(){
        return _firsetList.count();
    }


protected:
    void init(){}

protected:
    std::map<TYPE1,TYPE2>  _firsetList;
    std::map<TYPE2,TYPE1>  _secondList;
    typedef std::map<TYPE1, TYPE2>::iterator  FIRST_LIST_ITER;
    typedef std::map<TYPE2, TYPE1>::iterator  SECOND_LIST_ITER;
};





#endif //__GPairedMap_H_
