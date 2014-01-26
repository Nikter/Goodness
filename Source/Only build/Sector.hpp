#ifndef SECTOR_HPP
#define SECTOR_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <deque>

#include "Object.hpp"
#include "ListObject.hpp"

#include "Opponent.hpp"
#include "ListOpponent.hpp"

#include "OpponentMisterKuba.hpp"

class Sector {
        Object* Map[ 25 ][ 25 ];

        std::deque < Opponent* > Opponents;

        ListObject LObjects;
        ListOpponent LOpponents;

    public:
        Sector();

        void Logic();
        void Draw();
};

#endif // SECTOR_HPP
