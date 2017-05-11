//
//  Timer.hpp
//  FirstCPlusPlus
//
//  Created by Gallup, Tyler on 1/31/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>

class Timer
{
private:
    clock_t executionTime;
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExecutionTimeInMicroseconds();
    
};

#endif /* Timer_hpp */
