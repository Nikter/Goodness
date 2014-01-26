#include "ObjectGrass.hpp"

ObjectGrass::ObjectGrass()
    : Object( "grass" ) {

}

void ObjectGrass::Draw( int x, int y, ... ) {
    Graph::DrawTexture( "grass", x, y );
}

Object* GetObjectGrass() {
    return new ObjectGrass();
}
