#ifndef OPPONENTMISTERKUBA_HPP
#define OPPONENTMISTERKUBA_HPP

#include <cstdarg>

#include "Opponent.hpp"

#include "Graph.hpp"
#include "Timer.hpp"

class OpponentMisterKuba
    : public Opponent {
        Timer ti;

    public:
        OpponentMisterKuba( int x_, int y_ );

        virtual void Update();

        virtual void Draw( int Map_x, int Map_y, ... );
};

Opponent* GetOpponentMisterKuba( int x_, int y_ );

#endif // OPPONENTMISTERKUBA_HPP
