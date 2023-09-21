
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

namespace sdds{

class Timer{
    
    std::chrono::time_point<std::chrono::steady_clock> m_startTime{};
    
public:
    void start();
    long long stop();
    
    
};


}

#endif /* Timer_hpp */
