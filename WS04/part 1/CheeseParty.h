#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include "Cheese.h"

namespace sdds{
class CheeseParty{
    
    const Cheese** m_cheeseArr = nullptr;
    size_t m_size = 0;
public:
    CheeseParty() = default;
    CheeseParty& addCheese(const Cheese& addedElement);
    CheeseParty& removeCheese();
    friend std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty);
    ~CheeseParty();
    CheeseParty(const CheeseParty& RoP);
    CheeseParty(CheeseParty&& RoP);
    CheeseParty& operator=(const CheeseParty& RoP);
    CheeseParty& operator=(CheeseParty&& RoP);
};

}



#endif /* CheeseParty_hpp */
