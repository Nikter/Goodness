#ifndef OPPONENT_HPP
#define OPPONENT_HPP

#include <iostream>
#include <cstdarg>
#include <string>
#include <queue>
#include <conio.h>
#include <deque>

class Opponent {
        std::string ID;
        int x, y;

    public:
        Opponent( std::string ID_, int x_ = 0, int y_ = 0 );

        virtual void Update() = 0;
        virtual void Draw( int Map_x, int Map_y, ... ) = 0;

        int GetX() const { return x; }
        int GetY() const { return y; }

        void SetX( int x_ ) { x = x_; }
        void SetY( int y_ ) { y = y_; }
};

struct CompareOpponent {
    bool operator ()( const Opponent*  Opt_1, const Opponent*  Opt_2 );
};

typedef std::priority_queue < Opponent*, std::deque < Opponent* >, CompareOpponent > ContainerOpponent;

typedef Opponent*( * ReturnOpponent )( int, int );

#endif // OPPONENT_HPP
