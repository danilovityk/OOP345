// - Danylo Vityk
// - 176326213
// - dvityk@myseneca.ca
// - Oct 14, 2023


#include <iostream>
#include <iomanip>
#include "Movie.h"

using namespace std;

namespace sdds{

Movie::Movie() {
    
    m_title = "";
    m_year = 0;
    m_desc = "";
}

const std::string &Movie::title() const {
    return m_title;
}

Movie::Movie(const std::string &strMovie) {
    size_t i = 0;
    m_title = "";
    
    while(strMovie[i] != ','){
        m_title += strMovie[i];
        i++;
    }
    i++;
    
    string buff = "";
    while(strMovie[i] != ','){
        buff += strMovie[i];
        i++;
    }
    
    i++;
    m_year = stoi(buff);
    
    m_desc = "";
    while(i < strMovie.length()){
        m_desc += strMovie[i];
        i++;
    }
    
    m_desc = trim(m_desc);
    m_title = trim(m_title);
    
}

std::string Movie::trim(const std::string& input) {
    size_t start = input.find_first_not_of(" ");
    size_t end = input.find_last_not_of(" ");
    return input.substr(start, end - start + 1);
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << setw(40) << right
    << movie.m_title << " | "
    << setw(4) << movie.m_year << " | "
    << movie.m_desc
    << endl;
    return os;
}

}

