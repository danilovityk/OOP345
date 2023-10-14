// - Danylo Vityk
// - 176326213
// - dvityk@myseneca.ca
// - Oct 14, 2023


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "SpellChecker.h"

namespace sdds{

class Book{
    std::string m_author{};
    std::string m_title{};
    std::string m_country{};
    size_t m_year{};
    double m_price{};
    std::string m_description{};
    
public:
    std::string trim(const std::string& input);
    Book();
    Book(const std::string& strBook);
    double& price();
    const size_t& year() const;
    const std::string& country() const;
    const std::string& title() const;
    
    template <typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_description);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Book& book) ;

};




}


#endif /* Book_hpp */
