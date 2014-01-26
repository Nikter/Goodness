#include "OpponentMisterKuba.hpp"

OpponentMisterKuba::OpponentMisterKuba( int x_, int y_ )
    : Opponent( "misterkuba" )
    , ti( 1 ) {

    SetX( x_ );
    SetY( y_ );
}

void OpponentMisterKuba::Update() {
    if( ti.GetTime() ) {
        SetX( GetX() + 10 );

        ti.Update();
    }
}

void OpponentMisterKuba::Draw( int Map_x, int Map_y, ... ) {
    Graph::DrawTexture( "mister", GetX(), GetY());
}

Opponent* GetOpponentMisterKuba( int x_, int y_ ) {
    return new OpponentMisterKuba( x_, y_ );
}
