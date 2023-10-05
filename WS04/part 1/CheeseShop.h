
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include "Cheese.h"
namespace sdds{

class CheeseShop {
    std::string m_name{};
    const Cheese** m_cheese = nullptr;
    const Cheese** m_cheeseDeall = nullptr;
    size_t dealloSize = 0;
    size_t m_size = 0;
    
    void addCheeseDeall(const Cheese& cheeseSource);
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
