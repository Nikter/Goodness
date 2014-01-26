#include "ObjectStone.hpp"

ObjectStone::ObjectStone()
    : Object( "stone" ) {

}

void ObjectStone::Draw( int x, int y, ... ) {
    Graph::DrawTexture( "stone", x, y );
}

Object* GetObjectStone() {
    return new ObjectStone();
}
