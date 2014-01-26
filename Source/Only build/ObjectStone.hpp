#ifndef OBJECTSTONE_HPP
#define OBJECTSTONE_HPP

#include <cstdarg>

#include "Object.hpp"
#include "Graph.hpp"

class ObjectStone
    : public Object {
    public:
        ObjectStone();

        virtual void Draw( int x, int y, ... );
};

Object* GetObjectStone();

#endif // OBJECTSTONE_HPP
