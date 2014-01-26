#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Console.hpp"

class Graph {
        static std::map < std::string, ALLEGRO_BITMAP* > Img;
        static ALLEGRO_COLOR tmp_color;
    public:
        static void Init();


        static bool LoadImg( std::string ID, const char *FileName );

        static void DrawQuad( int x, int y, int w, int h );

        static void DrawQuadRGBA( int x, int y, int w, int h, ALLEGRO_COLOR Color );

        static void DrawTexture( std::string ID, int x, int y, int w = NULL, int h = NULL );

        static void DrawTextureColor( std::string ID, ALLEGRO_COLOR Color, int x, int y, int w = NULL, int h = NULL );
};

#endif // GRAPH_HPP
