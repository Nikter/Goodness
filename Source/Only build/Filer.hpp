#ifndef FILER_HPP
#define FILER_HPP

#include <iostream>
#include <iomanip>
#include <dirent.h>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/tuple/tuple.hpp>
#include <io.h>

#include "Console.hpp"

namespace Filer {
    class Element {
        public:
            std::string Address, Name;

            Element( std::string Address_, std::string Name_ );

            virtual void Print( int( * Filtr )( const Element & ) = NULL );
    };

    inline bool operator <( const Element & l, const Element & r );

    class File
        : public Element {
        public:
            File( std::string Address_, std::string Name_ );
    };

    class Folder
        : public Element {
        public:
            boost::ptr_set < Element > Elements;

            Folder( std::string Address_, std::string Name_ = "" );

            void Data();
            virtual void Print( int( * Filtr )( const Element & ) = NULL );
            static bool IsFolder( std::string Name_ );
    };
}

#endif // FILER_HPP
