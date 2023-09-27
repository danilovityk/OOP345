//
//  Book.cpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#include "Book.h"
using namespace std;

namespace sdds{



Book::Book(){
        
}
    
Book::Book(const std::string& title, unsigned nChapters, unsigned nPages){
    
    
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
    
        
}

std::ostream& Book::print(std::ostream& os) const{
    if(*this)
    {
        cout << m_title << ',' << m_numChapters << ',' << m_numPages << ',' << m_numPages / m_numChapters << endl;
    }
    
    return os;
}


Book::operator bool() const{
    bool flag = false;
    if (m_title[0] != '\0' && m_numPages > 0 && m_numChapters > 0){ // String boolean conversion fucked up
        flag = true;
    }
    
    return flag;
}


Book& Book::operator=(const Book& rOp){
    
    if(this != &rOp){
        
        m_title = rOp.m_title;
        m_numPages = rOp.m_numPages;
        m_numChapters = rOp.m_numChapters;
    }
    return *this;
}


bool Book::operator<(const Book& rOp){
    bool flag = false;
    
    if(m_numChapters < rOp.m_numChapters){
        flag = true;
    }
    
    
    return flag;
}



}
