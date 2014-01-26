#include "Event.hpp"

ALLEGRO_EVENT_QUEUE *Event::EventQueue;
ALLEGRO_MOUSE_STATE Event::Mouse;
bool Event::Keys[ ALLEGRO_KEY_MAX ];

void Event::Init() {
    al_install_keyboard(); Con.Write( NOR, "al_install_keyboard\n" );
    al_install_mouse(); Con.Write( NOR, "al_install_mouse\n" );

    EventQueue = al_create_event_queue();
    al_register_event_source( EventQueue, al_get_keyboard_event_source() );
}

bool Event::Update() {
    ALLEGRO_EVENT Events;
    ALLEGRO_TIMEOUT TimeOut;

    al_init_timeout( &TimeOut, 0.06f ); /// Time to wait for Event
    al_get_mouse_state( &Mouse );

    bool get_event = al_wait_for_event_until( EventQueue, &Events, &TimeOut );

    if( get_event )
        switch( Events.type ) {
            case ALLEGRO_EVENT_KEY_DOWN:
                if( Events.keyboard.keycode == ALLEGRO_KEY_ESCAPE )
                    return false;
                Keys[ Events.keyboard.keycode ] = true;
                break;

            case ALLEGRO_EVENT_KEY_UP:
                Keys[ Events.keyboard.keycode ] = false;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                return false;
                break;
        }

    return true;
}
