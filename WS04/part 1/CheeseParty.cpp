#include <iostream>
#include <iomanip>
#include "CheeseParty.h"

using namespace std;
namespace sdds{


CheeseParty &CheeseParty::addCheese(const Cheese &addedElement) {
    bool duplicate = false;
    for (int i = 0; i < int(m_size); i++){
        if (m_cheeseArr[i] == &addedElement) {duplicate = true;}
    }
        
    if (!duplicate){
        const Cheese** cheese = new const Cheese*[m_size + 1];
        
        for (int i = 0; i < int(m_size); i++) {
            cheese[i] = m_cheeseArr[i];
        }
        
        cheese[m_size] = &addedElement;
        ++m_size;
        
        delete[] m_cheeseArr;
        m_cheeseArr = cheese;
    }
       return *this;
}

CheeseParty &CheeseParty::removeCheese() {
    for(int i = 0; i < int(m_size); i++){
        if(m_cheeseArr[i]->getWeight() <= 0){m_cheeseArr[i] = nullptr;}
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty){
    
    os << setfill('-') << setw(26) << '-' << endl;
    os << "Cheese Party" << endl;
    os << setfill('-') << setw(26) << '-' << endl;
    os << setfill(' ');
    
    if(cheeseParty.m_cheeseArr) {
        for(int i = 0; i < int(cheeseParty.m_size); i++) {
               
            if (cheeseParty.m_cheeseArr[i]){ os << *cheeseParty.m_cheeseArr[i]; }
               
        }
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
       }
       else {
           
           os << "This party is just getting started!" << std::endl;
           os << setfill('-') << setw(26) << '-' << endl;
           os << setfill(' ');
       }
       return os;
}

CheeseParty::CheeseParty(const CheeseParty& RoP) {
    *this = RoP;
}

CheeseParty::CheeseParty(CheeseParty&& RoP) {
    *this = std::move(RoP);
}

CheeseParty& CheeseParty::operator=(const CheeseParty& RoP) {
    if(this != &RoP) {
        m_size = RoP.m_size;
        delete[] m_cheeseArr;
        m_cheeseArr = new const Cheese*[m_size];
        for(int i = 0; i < int(m_size); i++) {
            m_cheeseArr[i] = RoP.m_cheeseArr[i];
        }
    }
    return *this;
}

CheeseParty&CheeseParty::operator=(CheeseParty&& RoP) {
    if(this != &RoP) {
        delete[] m_cheeseArr;
        m_size = RoP.m_size;
        m_cheeseArr = RoP.m_cheeseArr;
        RoP.m_cheeseArr = nullptr;
    }
    return *this;
}

CheeseParty::~CheeseParty(){
    delete[] m_cheeseArr;
}

}



