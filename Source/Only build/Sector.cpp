#include "Sector.hpp"

Sector::Sector() {
    srand( time( NULL ) );

    int Random;

    for( int i = 0; i <= 24; i++ )
        for( int j = 0; j <= 24; j++ ) {
            Random =( rand() % 2 ) + 1;

            if( Random == 1 ) Map[ i ][ j ] = LObjects.GetObject( "grass" );
            else if( Random == 2 ) Map[ i ][ j ] = LObjects.GetObject( "stone" );
        }

    Opponents.push_back( LOpponents.GetOpponent( "misterkuba", 100, 100 ) );
    Opponents.push_back( LOpponents.GetOpponent( "misterkuba", 100, 50 ) );

    /*Opponents.push_back( new OpponentMisterKuba() );
    Opponents.push_back( new OpponentMisterKuba() );

    Opponents[ 1 ]->SetX( 100 );
    Opponents[ 1 ]->SetY( 50 );

    Opponents[ 0 ]->SetX( 100 );
    Opponents[ 0 ]->SetY( 100 );*/
}

void Sector::Logic() {
    for( size_t i = 0; i < Opponents.size(); i++ ) {
        Opponents[ i ]->Update();
    }
}

void Sector::Draw() {
    static ContainerOpponent OpponentsToDraw;

    for( int i = 0; i <= 24; i++ )
        for( int j = 0; j <= 24; j++ )
            Map[ i ][ j ]->Draw( (i * 64 / 2) + (j * 64 / 2), (i * 32 / 2) - (j * 32 / 2));

    for( size_t i = 0; i < Opponents.size(); i++ ) {
        OpponentsToDraw.push( Opponents[ i ] );

    }

    //Opponents[ 1 ]->Draw( 0, 0 );

    while( OpponentsToDraw.empty() == false ) {
        OpponentsToDraw.top()->Draw( 0, 0 );
        OpponentsToDraw.pop();
    }
}
