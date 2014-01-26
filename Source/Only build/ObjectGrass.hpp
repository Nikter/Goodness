#ifndef OBJECTGRASS_HPP
#define OBJECTGRASS_HPP

#include <cstdarg>

#include "Object.hpp"
#include "Graph.hpp"

class ObjectGrass
    : public Object {
    public:
        ObjectGrass();

        virtual void Draw( int x, int y, ... );
};

Object* GetObjectGrass();

#endif // OBJECTGRASS_HPP
