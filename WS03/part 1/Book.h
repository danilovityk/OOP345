//
//  Book.hpp
//  WS3
//
//  Created by Danik on 26.09.2023.
//

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds{


    class Book
    {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        
        // TODO: In completing Part 1, add here the missing
        // member prototypes that would be necessary for the
        // Collection module code and tester module w3_p1.cpp
        // to manage Book-type objects.
        //
        // In completing Part 2, add here the missing
        // member prototypes that would be necessary for
        // OrderedCollection module code and tester module
        // w3_p2.cpp to manage Book-type object.
        //
        // Write the implementations of these functions
        // in Book.cpp file
        double getRatio() const;
        std::ostream& print(std::ostream& os) const;
        operator bool() const;
        Book& operator=(const Book& rOp);
        bool operator<(const Book& rOp);
        bool operator>(const Book& rOp);
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
    



}

#endif /* Book_hpp */
