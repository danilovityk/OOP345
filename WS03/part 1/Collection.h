//
//  Collection.hpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Book.h"

namespace sdds{

template <typename T, unsigned int C>
class Collection{
private:
    T m_items[C];
    static T m_smallestItem;
    static T m_largestItem;
protected:
    void setSmallestItem(const T& item);
    void setLargestItem(const T& item);
public:
    T getSmallestItem();
    T getLargestItem();
    unsigned size() const;
    unsigned capacity() const;
    bool operator+=(const T& element);
    void print(std::ostream ostr) const;
};

template <>
class Collection<Book, 10>{
    Book m_items[10];
    Book m_smallestItem = {"", 1, 10000};
    Book m_largestItem = {"", 10000, 1};
    
protected:
    void setSmallestItem(const Book& item);
    void setLargestItem(const Book& item);
public:
    Book& getSmallestItem();
    Book& getLargestItem();
    unsigned size() const;
    unsigned capacity() const;
};




template <typename T, unsigned C>
T Collection<T, C>::m_smallestItem = -9999;
template <typename T, unsigned C>
T Collection<T, C>::m_largestItem = -9999;

}




#endif /* Collection_hpp */
