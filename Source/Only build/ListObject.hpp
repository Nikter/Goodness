#ifndef LISTOBJECT_HPP
#define LISTOBJECT_HPP

#include <string>
#include <map>

#include "Object.hpp"
#include "ObjectGrass.hpp"
#include "ObjectStone.hpp"

class ListObject {
        static std::map < std::string, ReturnObject > List;

    public:
        ListObject();

        Object* GetObject( std::string ID );
};

#endif // LISTOBJECT_HPP
