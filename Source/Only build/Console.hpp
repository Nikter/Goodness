#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <vector>
#include <queue>
#include <windows.h>

enum TypeColor {
    ERR,
    SPE,
    SPE2,
    NOR
};

class Console {
        static const DWORD BUFFER_SIZE;

        HANDLE HandleIn;
        HANDLE HandleOut;
        CRITICAL_SECTION CriticalSection;

        HANDLE Event;
        HANDLE ThreadHandle;

        std::vector < char > Buffer;
        std::queue < std::string > Queue;

        static DWORD WINAPI ReadThreadProc_s( void *This );
        DWORD ReadThreadProc();

    public:
        Console();
        ~Console();

        void SetTitle( const std::string &Title );

        void Write( TypeColor Type, const std::string &Text );

        bool InputQueueEmpty();
        bool GetInput( std::string *s );
        void WaitForInput();

        HANDLE GetWaitEvent() { return Event; }
};

extern Console Con;

#endif // CONSOLE_HPP
