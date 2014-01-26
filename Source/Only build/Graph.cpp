#include "Graph.hpp"

std::map < std::string, ALLEGRO_BITMAP* > Graph::Img;
ALLEGRO_COLOR Graph::tmp_color = al_map_rgb( 255, 255, 255 );

void Graph::Init() {
    al_init_primitives_addon(); Con.Write( NOR, "al_init_primitives_addon\n" );   ///  KONSOLA
    al_init_image_addon(); Con.Write( NOR, "al_init_image_addon\n" );             ///
}

bool Graph::LoadImg( std::string ID, const char *FileName ) {
    Img[ ID ] = al_load_bitmap( FileName );

    if( !Img[ ID ] ) {
        Con.Write( ERR, "Unable to load \"" );                          ///<---------------------------
        Con.Write( SPE, ID.c_str() );                                     ///      KONSOLA
        Con.Write( ERR, "\" from: \"" );                                  ///
        Con.Write( SPE, FileName ); Con.Write( ERR, "\".\n" );  ///<----------------------------

        return false;
    }

    al_convert_mask_to_alpha( Img[ ID ], al_map_rgb( 255, 255, 255 ));

    Con.Write( NOR, "\"" ); Con.Write( SPE, ID.c_str() ); /// <-----------------------------
    Con.Write( NOR, "\" has been loaded from: \"" );                  ///            KONSOLA
    Con.Write( SPE, FileName ); Con.Write( NOR, "\".\n" );  /// <-----------------------------

    return true;
}

void Graph::DrawQuad( int x, int y, int w, int h ) {
    al_draw_filled_rectangle( x, y, x + w, y + h, tmp_color );
}

void Graph::DrawQuadRGBA( int x, int y, int w, int h, ALLEGRO_COLOR Color ) {
    tmp_color = Color;

    al_draw_filled_rectangle( x, y, x + w, y + h, Color );
}

void Graph::DrawTexture( std::string ID, int x, int y, int w, int h ) {
    if( w == NULL ) w = al_get_bitmap_width( Img[ ID ] );
    if( h == NULL ) h = al_get_bitmap_height( Img[ ID ] );


    al_draw_scaled_bitmap( Img[ ID ], 0, 0,
                            al_get_bitmap_width( Img[ ID ] ), al_get_bitmap_height( Img[ ID ] ),
                            x, y,
                            w, h, 0 );
}

void Graph::DrawTextureColor( std::string ID, ALLEGRO_COLOR Color, int x, int y, int w, int h ) {
    if( w == NULL ) w = al_get_bitmap_width( Img[ ID ] );
    if( h == NULL ) h = al_get_bitmap_height( Img[ ID ] );

    al_draw_tinted_scaled_bitmap( Img[ ID ], Color, 0, 0,
                                    al_get_bitmap_width( Img[ ID ] ), al_get_bitmap_height( Img[ ID ] ),
                                    x, y,
                                    w, h, 0 );
}
