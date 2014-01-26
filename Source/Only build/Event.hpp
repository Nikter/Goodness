#ifndef EVENT_HPP
#define EVENT_HPP

#include <allegro5/allegro.h>

#include "Console.hpp"

class Event {
        static ALLEGRO_EVENT_QUEUE *EventQueue;
        static bool Keys[ ALLEGRO_KEY_MAX ];
    public:
        static ALLEGRO_MOUSE_STATE Mouse;
        static void Init();
        static bool Update();
};

#endif // EVENT_HPP
