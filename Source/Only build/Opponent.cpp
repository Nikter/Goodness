#include "Opponent.hpp"

Opponent::Opponent( std::string ID_, int x_, int y_ )
    : ID ( ID_ )
    , x( x_ )
    , y( y_ ) { }

bool CompareOpponent::operator ()( const Opponent*  Opt_1, const Opponent*  Opt_2 ) {

    if( Opt_1->GetY() > Opt_2->GetY() ) return true;

    if( Opt_1->GetY() < Opt_2->GetY() ) return false;

    return false;
}
