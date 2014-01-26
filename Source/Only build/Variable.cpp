#include "Variable.hpp"

namespace Variable {
    Element::Element( std::string Name_ )
        : Name( Name_ ) { }

    void Element::AddElement( Element element, std::string Path ) {

    }

    bool operator <( const Element & l, const Element & r ) {
        return l.Name < r.Name;
    }

    ///==============================================================================================///

    Tekst::Tekst( std::string Var_, std::string Name_ )
        : Element( Name_ )
        , Var( Var_ ) { }

    //=========================================================================//

    Liczba::Liczba( int Var_, std::string Name_ )
        : Element( Name_ )
        , Var( Var_ ) { }

    //=========================================================================//

    pLiczba::pLiczba( double Var_, std::string Name_ )
        : Element( Name_ )
        , Var( Var_ ) { }

    //=========================================================================//

    Wyb::Wyb( bool Var_, std::string Name_ )
        : Element( Name_ )
        , Var( Var_ ) { }

    ///==============================================================================================///

    Mapa::Mapa( std::string Name_ )
        : Element( Name_ ) { }

    void Mapa::AddElement( Element element, std::string Path ) {
        if( !strcmp( Path.c_str(), ";" ) ) {
            Elements.insert( element );

            return;
        }

        std::string Tmp;

        //Console::Write( NOR, Path.c_str() );

        int Pos = 0;
        bool Num, End, Add;

        while( true ) {
            if( Path[ Pos ] == ':'  ) { End = true; break; }
            else if( Path[ Pos ] == ';' ) { Add = true; break; }
            else if( Path[ Pos ] == '$' ) { Num = true; break; }
            else {
                Tmp += Path[ Pos++ ];
            }
        }

        if( End ) {
            if( Num ) {
                std::string sss;

                int Amount, TmpAmount = 0;
                std::istringstream ss( Tmp );
                ss >> Amount;

                /*for( boost::ptr_set < Element > ::iterator iter = Elements.begin(); iter != Elements.end(); ++iter ) {
                    sss = iter->Name;

                    if( Amount == TmpAmount ) iter->AddElement( element, Path.erase( 0, Pos ) );
                    if( !strcmp( sss.c_str(), "." ) ) TmpAmount++;
                }*/
            } else {
                /*for( boost::ptr_set < Element >::iterator it = Elements.begin(); it != Elements.end(); ++it ) {
                    if( it->Name == Tmp ) it->AddElement( element, Path.erase( 0, Pos ) );
                }*/
            }
        } else if( Add ) {
            Elements.insert( element );
        }

        //Console::Write( NOR, Tmp.c_str() );
    }

    Element Mapa::GetElement( std::string Path ) {
        Wyb ss( true, "prawda" );
        return ss;
    }

    /*/=========================================================================//

    List::List( std::string Name_ )
        : Element( Name_ ) { }

    void List::AddElement( Element element, std::string Path ) {

    }

    Element List::GetElement( std::string Path ) {

    }*/


}
