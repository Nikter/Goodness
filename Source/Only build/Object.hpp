#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <cstdarg>
#include <string>

class Object {
        std::string ID;

    public:
        Object( std::string ID_ );

        virtual void Draw( int x, int y, ... ) = 0;
};

typedef Object*( * ReturnObject )();

#endif // OBJECT_HPP
