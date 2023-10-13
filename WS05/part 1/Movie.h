#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds{
class Movie{
    std::string m_title;
    size_t m_year;
    std::string m_desc;
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    std::string trim(const std::string& input);
    
    template <typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_desc);
        spellChecker(m_title);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
       
    
};




}

#endif /* Movie_hpp */
