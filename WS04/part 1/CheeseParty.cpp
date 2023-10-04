#include <iostream>
#include "CheeseParty.h"
namespace sdds{


CheeseParty &CheeseParty::addCheese(const Cheese &addedElement) {
    
    const Cheese* cheese[sizeof(m_cheeseArr) / sizeof(m_cheeseArr[0]) + 1];
    
    for (int i = 0; i < sizeof(m_cheeseArr) / sizeof(m_cheeseArr[0]); i++){
        cheese[i] = m_cheeseArr[i];
    }
    
    cheese[sizeof(m_cheeseArr) / sizeof(m_cheeseArr[0])] = &addedElement;
    
    m_cheeseArr = cheese;
    return *this;
}

CheeseParty &CheeseParty::removeCheese() {
    for(int i = 0; i < sizeof(m_cheeseArr) / sizeof(m_cheeseArr[0]); i++){
        if(m_cheeseArr[i]->getWeight() <= 0){m_cheeseArr[i] = nullptr;}
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty){
    
    
    if(sizeof(**cheeseParty.m_cheeseArr) / sizeof(*cheeseParty.m_cheeseArr[0])) {
           for(int i = 0; i < sizeof(**cheeseParty.m_cheeseArr) / sizeof(*cheeseParty.m_cheeseArr[0]); i++) {
               os << cheeseParty.m_cheeseArr[i];
           }
       }
       else {
           os << "This party is out of cheese!" << std::endl;
       }
       return os;
}


}



