
//- Danylo Vityk
//- 176326213
//- dvityk@myseneca.ca
//- Sep 20, 2023


#include <chrono>
#include "Timer.h"

using namespace std;

namespace sdds{

    void Timer::start() {
        m_startTime = chrono::steady_clock::now();
    }

    long long Timer::stop() {
        auto endTime = chrono::steady_clock::now();
        
        return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_startTime).count();
    }

}
