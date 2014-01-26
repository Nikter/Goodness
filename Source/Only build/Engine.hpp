#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <windows.h>

#include <allegro5/allegro.h>

#include "Event.hpp"
#include "Graph.hpp"
#include "Console.hpp"

#include "Sector.hpp"
#include "Timer.hpp"

class Engine {
        ALLEGRO_DISPLAY *Display;
        std::string DisplayName;
        const int Width, Height; //SZEROKOSC, WYSOKOSC

    public:
        Engine( std::string DisplayName_, const int Width_, const int Height_ );

        void Load();

        void Update();
};

#endif // MAIN_HPP
