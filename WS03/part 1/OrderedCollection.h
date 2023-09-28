//
//  OrderedCollection.hpp
//  WS3
//
//  Created by Danik on 27.09.2023.
//

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h"
namespace sdds{

template <typename T>
class OrderedCollection : public Collection<T, 72>{
    
public:
    virtual bool operator+=(const T& element){
            
        bool flag = Collection<T, 72>::operator+=(element);
        bool sorted = false;
        if(flag){
            do {
                sorted = false;
                
                for (unsigned i = 0; i < Collection<T, 72>::size() - 1 ; i++){
                    if(Collection<T, 72>::operator[](i) > Collection<T, 72>::operator[](i+1)){
                        
                        T temp = Collection<T, 72>::operator[](i);
                        Collection<T, 72>::operator[](i) = Collection<T, 72>::operator[](i+1);
                        Collection<T, 72>::operator[](i+1) = temp;
                        
                        sorted = true;
                    }
                }
                
                
                
                
            }while(sorted);
        }
        return flag;
    }
    
    
    
//    static T getLargestItem() {
//        return Collection<T, 72>::getLargestItem();
//    }
//
//    static T getSmallestItem() {
//        return Collection<T, 72>::getSmallestItem();
//    }
    
};



}

#endif /* OrderedCollection_hpp */
