#include "Engine.hpp"


Engine::Engine( std::string DisplayName_, const int Width_, const int Height_ )
    : DisplayName( DisplayName_ )
    , Width( Width_ )
    , Height( Height_ ) {

    Display = al_create_display( Width, Height );
    al_set_window_title( Display, DisplayName.c_str() );

    this->Load();
}

void Engine::Load() {
    Event::Init();
    Graph::Init();

    this->Update();
}

void Engine::Update() {
    Graph::LoadImg( "grass", "\grass.png" );
    Graph::LoadImg( "stone", "\stone.png" );

    Graph::LoadImg( "mister", "\mister.png" );

    Sector maaapa;
    //Map maps( "object.wall" );

    //Timer timer( 1 );
    //CreateThread( NULL, 0, TimerMain, ( LPVOID )&timer, 0, NULL );

    int Frames = 0, Fps;
    double TimeOne = al_get_time(), TimeTwo;
    double FpsTime = 0;

    while( true ) {
        std::string Command;
		while( Con.GetInput( &Command )) {
			if( Command == "!exit" )
				exit( EXIT_SUCCESS );
		}

        if( !Event::Update() )
            exit( EXIT_SUCCESS );


        TimeTwo = al_get_time();
        double DeltaTime = TimeTwo - TimeOne;     // czas generowania ostatniej klatki
        TimeTwo = TimeOne;

        ///---------------------------------------------------DELTA TIME----------------------------------------///

        ++Frames;
        FpsTime += DeltaTime;
        if( FpsTime >= 1.0 ) {
            Fps = FpsTime / Frames;
            FpsTime = 0;
            Frames = 0;
        }

        maaapa.Logic();
        maaapa.Draw();

        al_flip_display();
        al_clear_to_color( al_map_rgb( 128, 128, 128 ));

    }
}
