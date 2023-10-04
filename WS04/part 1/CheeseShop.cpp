#include <iostream>
#include <iomanip>
#include "CheeseShop.h"

using namespace std;

namespace sdds{


CheeseShop::CheeseShop(const std::string &name) {
    m_name = name;
}

CheeseShop &CheeseShop::addCheese(const Cheese& cheeseSource) {
    
    Cheese *addedCheese = new Cheese(cheeseSource);
    
    const Cheese** cheese = new const Cheese*[m_size + 1];
    
   
    for (int i = 0; i < int(m_size); i++){
        cheese[i] = m_cheese[i];
    }
    
    cheese[m_size] = addedCheese;
    ++m_size;
    delete[] m_cheese;
    m_cheese = cheese;
    return *this;
    
}

CheeseShop::CheeseShop(const CheeseShop &source) {
    *this = source;
}

CheeseShop &CheeseShop::operator=(const CheeseShop &RoP) { 
    if (this != &RoP){
        
        m_name = RoP.m_name;
        m_size = RoP.m_size;
        m_cheese = new const Cheese*[m_size];
        
        for(int i = 0; i < int(m_size); i++){
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
    m_size = RoP.m_size;
    
    RoP.m_name = "";
    RoP.m_cheese = nullptr;
    
    return *this;
}

CheeseShop::CheeseShop(CheeseShop &&source) {
    *this = std::move(source);
}


std::ostream& operator<<(std::ostream& os, CheeseShop& cheeseShop){
    
    if(cheeseShop.m_cheese) {
        os << setfill('-') << setw(26) << '-' << endl;
        os << cheeseShop.m_name << endl;
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
           for(int i = 0; i < int(cheeseShop.m_size); i++) {
               os << *cheeseShop.m_cheese[i];
           }
       
       }
        
       else {
           os << setfill('-') << setw(26) << '-' << endl;
           os << cheeseShop.m_name << endl;
           os << setfill('-') << setw(26) << '-' << endl;
           os << setfill(' ');
           os << "This shop is out of cheese!" << std::endl;
       }
       return os;
    
}



}

