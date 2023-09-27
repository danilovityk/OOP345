//
//  Collection.cpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds{


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
    return m_size;
}

unsigned int Collection<Book, 10>::capacity() const { 
    return 10;
}

//void Collection<Book, 10>::print(std::ostream ostr) const {
//    if (*this){
//        
//
//    }else{
//        ostr << "| Invalid book data |" << endl;
//    }
//}


}
