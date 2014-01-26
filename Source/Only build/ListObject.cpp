#include "ListObject.hpp"

std::map < std::string, ReturnObject > ListObject::List;

ListObject::ListObject() {
    List[ "grass" ] = GetObjectGrass;
    List[ "stone" ] = GetObjectStone;
}

Object* ListObject::GetObject( std::string ID ) {
    return List[ ID ]();
}
