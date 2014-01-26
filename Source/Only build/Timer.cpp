#include "Timer.hpp"

Timer::Timer( double Ms_ )
    : Ms( Ms_ ) {

    this->Update();
}

void Timer::Update() {
    Time = al_get_time();
}

bool Timer::GetTime() {
    if( al_get_time() > ( Time + Ms ) ) return true;

    return false;
}
