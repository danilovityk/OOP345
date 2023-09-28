//
//  Collection.hpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include "Book.h"

namespace sdds{

template <typename T, unsigned C>
class Collection{
private:
    static T m_smallestItem;
    static T m_largestItem;
    unsigned m_size = 0;
   
protected:
    T m_items[C];
    T& operator[](unsigned index) {
        return m_items[index];
    }
    void incrSize(){
        ++m_size;
    };
    void setSmallestItem(const T& item){
        if (item < m_smallestItem){
            m_smallestItem = item;
        }
    }
    void setLargestItem(const T& item){
        if (item > m_largestItem){
            m_largestItem = item;
        }
    }
    
public:
    
    static T getLargestItem() {
        return m_largestItem;
    }
    
    static T getSmallestItem() {
        return m_smallestItem;
    }

    unsigned size() const{
        return m_size;
    }
    unsigned capacity() const{
        return C;
    }
    virtual bool operator+=(const T& element){
        bool flag = true;
        if (size() < capacity()){
            setSmallestItem(element);
            setLargestItem(element);
            
            
            m_items[m_size++] = element;
            flag = true;
            
        }else{
            flag = false;
        }
        return flag;
    }
    void print(std::ostream& ostr) const{
        ostr << "[";
        for(unsigned i = 0; i < size(); i++){
            ostr << m_items[i];
            if(i < size() - 1){ostr << ',';}
        }
        ostr << "]" << std::endl;
    }

};

template <>
class Collection<Book, 10>{
   
    Book m_smallestItem = {"", 1, 10000};
    Book m_largestItem = {"", 10000, 1};
    unsigned m_size = 0;
protected:
    Book m_items[10];
    void setSmallestItem(const sdds::Book &item) {
        if (item.getRatio() < m_smallestItem.getRatio()){
            m_smallestItem = item;
        }
    }
    void setLargestItem(const sdds::Book &item) {
        if (item.getRatio() > m_largestItem.getRatio()){
            m_largestItem = item;
        };
    }
    Book& operator[](unsigned index) {
        return m_items[index];
    }
    void incrSize(){
        ++m_size;
    };
public:
    void print(std::ostream& ostr) const{
        ostr << "| ---------------------------------------------------------------------------|" << std::endl;
        for(unsigned i = 0; i < size(); i++){
            ostr<<"| ";
            ostr << m_items[i];
            ostr << " |" << std::endl;
        }
        ostr << "| ---------------------------------------------------------------------------|" << std::endl;
        
    }
    
    Book& getSmallestItem() {
        return m_smallestItem;
    }
    
    Book& getLargestItem() {
        return m_largestItem;
    }

    unsigned int size() const {
        return m_size;
    }
    unsigned int capacity() const {
        return 10;
    }
    
    virtual bool operator+=(const Book& element){
        bool flag = true;
        if (size() < capacity()){
            setSmallestItem(element);
            setLargestItem(element);
            
            
            m_items[m_size++] = element;
            flag = true;
            
        }else{
            flag = false;
        }
        return flag;
    }
};

template <>
class Collection<Book, 72>{
   
    Book m_smallestItem = {"", 1, 10000};
    Book m_largestItem = {"", 10000, 1};
    unsigned m_size = 0;
protected:
    Book m_items[10];
    void setSmallestItem(const sdds::Book &item) {
        if (item.getRatio() < m_smallestItem.getRatio()){
            m_smallestItem = item;
        }
    }
    void setLargestItem(const sdds::Book &item) {
        if (item.getRatio() > m_largestItem.getRatio()){
            m_largestItem = item;
        };
    }
    Book& operator[](unsigned index) {
        return m_items[index];
    }
    void incrSize(){
        ++m_size;
    };

public:
    void print(std::ostream& ostr) const{
        ostr << "| ---------------------------------------------------------------------------|" << std::endl;
        for(unsigned i = 0; i < size(); i++){
            ostr<<"| ";
            ostr << m_items[i];
            ostr << " |" << std::endl;
        }
        ostr << "| ---------------------------------------------------------------------------|" << std::endl;
    }
    virtual bool operator+=(const Book& element){
        bool flag = true;
        if (size() < capacity()){
            setSmallestItem(element);
            setLargestItem(element);
            
            
            m_items[m_size++] = element;
            flag = true;
            
        }else{
            flag = false;
        }
        return flag;
    }
    Book& getSmallestItem() {
        return m_smallestItem;
    }
    
    Book& getLargestItem() {
        return m_largestItem;
    }

    unsigned int size() const {
        return m_size;
    }
    unsigned int capacity() const {
        return 72;
    }
    //    void print(std::ostream ostr) const;
};



template <typename T, unsigned C>
T Collection<T, C>::m_smallestItem = 9999;
template <typename T, unsigned C>
T Collection<T, C>::m_largestItem = -9999;

}




#endif /* Collection_hpp */
