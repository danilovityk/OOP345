//
//  Collection.cpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#include "Collection.h"

namespace sdds{

template <typename T, unsigned int C>
void Collection<T,C>::setSmallestItem(const T& item){
    if (item < m_smallestItem){
        m_smallestItem = item;
    }
}

template <typename T, unsigned int C>
void Collection<T,C>::setLargestItem(const T& item){
    if (item > m_largestItem){
        m_largestItem = item;
    }
}


template <typename T, unsigned int C>
T Collection<T,C>::getSmallestItem(){
    return m_smallestItem;
}

template <typename T, unsigned int C>
T Collection<T,C>::getLargestItem(){
    return m_largestItem;
}


template <typename T, unsigned int C>
unsigned Collection<T,C>::size() const{
    
    return sizeof(*m_items)/sizeof(T);
}


template <typename T, unsigned int C>
unsigned Collection<T,C>::capacity() const{
    
    return C;
}


template <typename T, unsigned int C>
bool Collection<T,C>::operator+=(const T& element){
    bool flag = true;
    if (size() < capacity()){
        setSmallestItem(element);
        setLargestItem(element);
        
        
        m_items[size()] = element;
        flag = true;
        
    }else{
        flag = false;
    }
    return flag;
}


template <typename T, unsigned int C>
void Collection<T,C>::print(std::ostream ostr) const{
    ostr << "[";
    for(unsigned i = 0; i < size(); i++){
        ostr << m_items << ',';
    }
    ostr << "]";
}



void Collection<Book, 10>::setSmallestItem(const sdds::Book &item) { 
    if (item < m_smallestItem){
        m_smallestItem = item;
    }
}

void Collection<Book, 10>::setLargestItem(const sdds::Book &item) { 
    if (item > m_largestItem){
        m_largestItem = item;
    };
}

sdds::Book &Collection<Book, 10>::getSmallestItem() { 
    return m_smallestItem;
}

sdds::Book &Collection<Book, 10>::getLargestItem() { 
    return m_largestItem;
}

unsigned int Collection<Book, 10>::size() const { 
    return sizeof(*m_items)/sizeof(Book);
}

unsigned int Collection<Book, 10>::capacity() const { 
    return 10;
}

}
