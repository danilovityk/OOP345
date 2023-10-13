#include <iostream>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds{

size_t SpellChecker::m_counter[ARRAY_SIZE]{};


SpellChecker::SpellChecker(const char* filename) {
    ifstream file(filename);
    
    if (!file) {
        throw "Bad file name!";
    }
    
    std::string buffer;
    
    for (int i = 0; i < ARRAY_SIZE; i++){
     
        std::getline(file, buffer);
        int j = 0;
        while(buffer[j] != ' '){
            m_badWords[i] += buffer[j];
            j++;
        }
        
        
        
        while(j < buffer.length()){
            if (buffer[j] != ' '){
                m_goodWords[i] += buffer[j];
            }
            j++;
        }
        
        
    }
     
     
   
    file.close();

}

void SpellChecker::operator()(std::string& text) {
    for (int i = 0; i < ARRAY_SIZE; i++){
        size_t index = text.find(m_badWords[i]);
        if (index != std::string::npos){
            text.replace(index, m_badWords[i].length(), m_goodWords[i]);
            ++m_counter[i];
        }
        index = text.find(m_badWords[i]);
        if (index != std::string::npos){
            --i;
        }
    }
}

void SpellChecker::showStatistics(std::ostream& out) const {
    out << "Spellchecker Statistics" << std::endl;
    for(int i = 0; i < ARRAY_SIZE; i++){
        out << setw(15) << right << m_badWords[i] << ": " << m_counter[i] << " replacements" << endl;
    }
}



}

