#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <string>
#include <list>

#include <boost/ptr_container/ptr_set.hpp>


#include "Console.hpp"

namespace Variable {
    class Element {
        public:
            std::string Name;

            Element( std::string Name_ );

            virtual void AddElement( Element element, std::string Path );
    };

    bool operator <( const Element & l, const Element & r );

    //=========================================================================//

    class Tekst
        : public Element {
        public:
            std::string Var;

            Tekst( std::string Var_, std::string Name_ = "." );
    };

    //=========================================================================//

    class Liczba
        : public Element {
        public:
            int Var;

            Liczba( int Var_, std::string Name_ = "." );
    };

    //=========================================================================//

    class pLiczba
        : public Element {
        public:
            double Var;

            pLiczba( double Var_, std::string Name_ = "." );
    };

    //=========================================================================//

    class Wyb
        : public Element {
        public:
            bool Var;

            Wyb( bool Var_, std::string Name_ = "." );
    };

    ///===============================================================================================///

    class Mapa
        : public Element {
            boost::ptr_set < Element > Elements;

        public:
            Mapa( std::string Name_ = "." );

            void AddElement( Element element, std::string Path = ";" );
            Element GetElement( std::string Path = "$0;" );
    };

    //=========================================================================//

    /*class List
        : public Element {
            boost::ptr_set < Element > Elements;
        public:

            List( std::string Name_ = "." );

            void AddElement( Element element, std::string Path = ";" );
            Element GetElement( std::string Path = "$0;" );
    };*/
}

#endif // VARIABLE_HPP
