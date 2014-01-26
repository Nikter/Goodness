#include <iostream>

#include <string>

#include "Engine.hpp"
#include "Console.hpp"

int main() {
    {
        Con.Write( NOR, "Build: " );
        Con.Write( NOR, __DATE__ );
        Con.Write( NOR, " " );
        Con.Write( NOR, __TIME__ );
        Con.Write( NOR, "\n" );
    }

    al_init(); Con.Write( NOR, "al_init \n" );

    Engine engine( "Oh, my goodness !", 1280, 720 );


    return 0;
}
