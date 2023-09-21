//
//  Timer.cpp
//  w2p2
//
//  Created by Danik on 20.09.2023.
//

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
