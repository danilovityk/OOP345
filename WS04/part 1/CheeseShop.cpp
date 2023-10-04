#include <iostream>
#include "CheeseShop.h"

namespace sdds{


CheeseShop::CheeseShop(const std::string &name) {
    m_name = name;
}

CheeseShop &CheeseShop::addCheese(const Cheese& cheeseSource) {
    
    if(m_cheese != nullptr){
        std::cout << sizeof(m_cheese) / sizeof(m_cheese[0]) << " - size before memory allocation" << std::endl;
        const Cheese** cheese = new const Cheese*[((sizeof(**m_cheese) / sizeof(*m_cheese[0])) + 1)];
        
        
            for (int i = 0; i < (sizeof(**m_cheese) / sizeof(*m_cheese[0])); i++){
                cheese[i] = m_cheese[i];
            }
        
        cheese[sizeof(**m_cheese) / sizeof(*m_cheese[0])] = &cheeseSource;
        
        std::cout << sizeof(**cheesxe) / sizeof(*cheese[0]) << std::endl;
        for (int i = 0; i < (sizeof(**cheese) / sizeof(*cheese[0])); i++){
            std::cout << cheese[i];
        } //test loop
            
        
        delete[] m_cheese;
        m_cheese = cheese;
    }else{
        const Cheese** cheese = new const Cheese*[1];
        cheese[0] = &cheeseSource;
        m_cheese = cheese;
    }
    return *this;
    
}

CheeseShop::CheeseShop(const CheeseShop &source) {
    *this = source;
}

CheeseShop &CheeseShop::operator=(const CheeseShop &RoP) { 
    if (this != &RoP){
        
        m_name = RoP.m_name;
        
        m_cheese = new const Cheese*[sizeof(RoP.m_cheese) / sizeof(RoP.m_cheese[0])];
        
        for(int i = 0; i < sizeof(RoP.m_cheese) / sizeof(RoP.m_cheese[0]); i++){
            m_cheese[i] = RoP.m_cheese[i];
        }
        
    }
    
    return *this;
}

CheeseShop::~CheeseShop() { 
    delete[] m_cheese;
}


CheeseShop &CheeseShop::operator=(CheeseShop &&RoP) {
    delete[] m_cheese;
    m_name = RoP.m_name;
    m_cheese = RoP.m_cheese;
    
    RoP.m_name = "";
    RoP.m_cheese = nullptr;
    
    return *this;
}

CheeseShop::CheeseShop(CheeseShop &&source) {
    *this = std::move(source);
}


std::ostream& operator<<(std::ostream& os, CheeseShop& cheeseShop){
    
    if(cheeseShop.m_cheese) {
           for(int i = 0; i < sizeof(cheeseShop.m_cheese) / sizeof(cheeseShop.m_cheese[0]); i++) {
               os << *cheeseShop.m_cheese[i];
           }
       }
       else {
           os << "This shop is out of cheese!" << std::endl;
       }
       return os;
    
}



}

