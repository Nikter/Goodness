#include "Filer.hpp"
namespace Filer {
    Element::Element( std::string Address_, std::string Name_ )
        : Address( Address_ )
        , Name( Name_ ) { }

    void Element::Print( int( * Filtr )( const Element & ) ) {
        if( Filtr == NULL ) {
            Console::Write( SPE, Address ); Console::Write( NOR, "\n" );
        } else if( Filtr( * this ) ) {
            Console::Write( SPE, Address ); Console::Write( NOR, "\n" );
        }
    }

    bool operator <( const Element & l, const Element & r ) {
        return l.Name < r.Name;
    }

    ///===========================================================================================================================================///

    File::File( std::string Address_, std::string Name_ )
        : Element( Address_, Name_ ) { }

    ///===========================================================================================================================================///

    Folder::Folder( std::string Address_, std::string Name_ )
        : Element( Address_, Name_ ) {
        this->Data();
    }

    void Folder::Data() {
        _finddata_t DataFile;
        int Find = 0;

        std::string TmpAddress = Address + "/" + "*.*";
        int Handle = _findfirst( TmpAddress.c_str(), &DataFile );

        while( Find != -1 ) {
            std::string AddressCurrent = ( Address + "/" + DataFile.name );

            if( !strcmp( DataFile.name, "." ) ) {
            } else if( !strcmp( DataFile.name, ".." ) ) {
            } else if( IsFolder( DataFile.name ) ) {
                Elements.insert( new Folder( AddressCurrent, DataFile.name ) );
            } else {
                Elements.insert( new File( AddressCurrent, DataFile.name ) );
            }

            Find = _findnext( Handle, &DataFile );
        }
    }

    void Folder::Print( int( * Filtr )( const Element & ) ) {
        //Console::Write( SPE, Address ); Console::Write( NOR, "\n" );

        for( boost::ptr_set < Element >::iterator it = Elements.begin(); it != Elements.end(); ++it )
            it->Print( Filtr );
    }

    bool Folder::IsFolder( std::string Name_ ) {
        if( Name_.find( "." ) != std::string::npos ) return false;

        return true;
    }
}
