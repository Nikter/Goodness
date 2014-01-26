#include "ListOpponent.hpp"

std::map < std::string, ReturnOpponent > ListOpponent::List;

ListOpponent::ListOpponent() {
    List[ "misterkuba" ] = GetOpponentMisterKuba;
}

Opponent* ListOpponent::GetOpponent( std::string ID, int x, int y ) {
    return List[ ID ]( x, y );
}
