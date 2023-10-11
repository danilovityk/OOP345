#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;

namespace sdds {

Book::Book(){
    m_author = "";
    m_title = "";
    m_country = "";
    m_year = 0;
    m_price = 0;
    m_description = "";
}

Book::Book(const std::string &strBook) {
    size_t i = 0;
    m_author = "";
        while(strBook[i] != ','){
            m_author += strBook[i];
            i++;
        }
        i++;
    
    m_title = "";
        while(strBook[i] != ','){
            m_title += strBook[i];
            i++;
        }
        i++;
    
    m_country = "";
        while(strBook[i] != ','){
            m_country += strBook[i];
            i++;
        }
        i++;
    
    string buff = "";
            while(strBook[i] != ','){
                buff += strBook[i];
                i++;
            }
            i++;
    m_price = stod(buff);
    
    buff = "";
            while(strBook[i] != ','){
                buff += strBook[i];
                i++;
            }
            i++;
    m_year = stoi(buff);
    
    m_description = "";
        while(i < strBook.length()){
            m_description += strBook[i];
            i++;
        }
        
    m_title = trim(m_title);
    m_author = trim(m_author);
    m_country = trim(m_country);
    m_description = trim(m_description);
    
    
}

double &Book::price() {
    return m_price;
}

const size_t &Book::year() const {
    return m_year;
}

const std::string &Book::country() const {
    return m_country;
}

const std::string &Book::title() const {
    return m_title;
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    
    os << setw(20) << right << book.m_author << " | "
    << setw(22) << right << book.m_title << " | "
    << setw(5) << right << book.m_country << " | "
    << setw(4) << right << book.m_year << " | "
    << setw(6) << setprecision(2) << fixed << book.m_price << " | "
    << book.m_description << endl;
    
    return os;
}

std::string Book::trim(const std::string& input) {
    size_t start = input.find_first_not_of(" ");
    size_t end = input.find_last_not_of(" ");
    return input.substr(start, end - start + 1);
}

}



