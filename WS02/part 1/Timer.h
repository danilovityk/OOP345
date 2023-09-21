
//- Danylo Vityk
//- 176326213
//- dvityk@myseneca.ca
//- Sep 20, 2023


#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds{

class Timer{
    
    std::chrono::time_point<std::chrono::steady_clock> m_startTime{};
    
public:
    void start();
    long long stop();
    
    
};


}

#endif /* Timer_hpp */
