#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include "Cheese.h"

namespace sdds{
class CheeseParty{
    
    const Cheese** m_cheeseArr;
public:
    CheeseParty() = default;
    CheeseParty& addCheese(const Cheese& addedElement);
    CheeseParty& removeCheese();
    friend std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty);
};

}



#endif /* CheeseParty_hpp */
