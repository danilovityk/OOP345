#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#define ARRAY_SIZE 6

namespace sdds {

class SpellChecker{
  
    std::string m_badWords[ARRAY_SIZE]{};
    std::string m_goodWords[ARRAY_SIZE]{};
    static size_t m_counter[ARRAY_SIZE];
    
    
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
    
};


}

#endif /* SpellChecker_hpp */
