#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;

public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    double stop() {
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> elapsed = endTime - startTime;
        return elapsed.count(); // microseconds
    }
    
};

#endif
