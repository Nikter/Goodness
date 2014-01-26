#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <string>
#include <list>
#include <windows.h>
#include <stdio.h>

#include <allegro5/allegro.h>

class Timer {
        double Time, Ms;

    public:
        Timer( double Ms_ );

        void Update();

        bool GetTime();
};

#endif // TIMER_HPP
