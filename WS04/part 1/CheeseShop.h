//- Danylo Vityk
//- 176326213
//- dvityk@myseneca.ca
//- Oct 5, 2023

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include "Cheese.h"
namespace sdds{

class CheeseShop {
    std::string m_name{};
    const Cheese** m_cheese = nullptr;
    size_t m_size = 0;
    
public:
    CheeseShop() = default;
    CheeseShop(const CheeseShop& source);
    CheeseShop(CheeseShop&& source);
    CheeseShop& operator=(const CheeseShop& RoP);
    CheeseShop& operator=(CheeseShop&& RoP);
    ~CheeseShop();
    CheeseShop(const std::string& name = "No Name");
    CheeseShop& addCheese(const Cheese& cheeseSource);
    friend std::ostream& operator<<(std::ostream& os, CheeseShop& cheeseShop);
};

}

#endif /* CheeseShop_hpp */
