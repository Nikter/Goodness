#ifndef LISTOPPONENT_HPP
#define LISTOPPONENT_HPP

#include <string>
#include <map>

#include "Opponent.hpp"
#include "OpponentMisterKuba.hpp"

class ListOpponent {
        static std::map < std::string, ReturnOpponent > List;

    public:
        ListOpponent();

        Opponent* GetOpponent( std::string ID, int x, int y );
};

#endif // LISTOPPONENT_HPP
