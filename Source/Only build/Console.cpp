#include "Console.hpp"

#include <string>
#include <vector>
#include <queue>
#include <windows.h>

const DWORD Console::BUFFER_SIZE = 1024;

Console::Console() :
	HandleIn( 0 ),
	HandleOut( 0 ),
	ThreadHandle( 0 ),
	Event( 0 ) {
	Buffer.resize( BUFFER_SIZE + 1 );

	AllocConsole();

	HandleIn = GetStdHandle( STD_INPUT_HANDLE );
	HandleOut = GetStdHandle( STD_OUTPUT_HANDLE );

	InitializeCriticalSection( &CriticalSection );
	Event = CreateEvent( 0, TRUE, FALSE, 0 );
	ThreadHandle = CreateThread( 0, 0, &ReadThreadProc_s, this, 0, 0 );
}

Console::~Console() {
	TerminateThread( ThreadHandle, 0 );
	CloseHandle( Event );
	DeleteCriticalSection( &CriticalSection );
	FreeConsole();
}

void Console::SetTitle( const std::string &Title ) {
	SetConsoleTitle( Title.c_str());
}

void Console::Write( TypeColor Type, const std::string &Text ) {
    switch( Type ) {
        case ERR:
            SetConsoleTextAttribute( HandleOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
            break;
        case SPE:
            SetConsoleTextAttribute( HandleOut, FOREGROUND_GREEN );
            break;
        case SPE2:
            SetConsoleTextAttribute( HandleOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            break;
        case NOR:
            SetConsoleTextAttribute( HandleOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
    }

    DWORD Foo;
    WriteConsole( HandleOut, Text.data(), ( DWORD )Text.length(), &Foo, 0 );
    SetConsoleTextAttribute( HandleOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
}

DWORD WINAPI Console::ReadThreadProc_s( void *This ) {
	return (( Console* ) This ) -> ReadThreadProc();
}

DWORD Console::ReadThreadProc() {
	DWORD CharactersRead;
	std::string s;

	while( true ) {
		ReadConsole( HandleIn, &Buffer[ 0 ], BUFFER_SIZE, &CharactersRead, 0 );

		EnterCriticalSection( &CriticalSection );
		s.assign( &Buffer[ 0 ], CharactersRead - 2 ); // -2, bo bez koñca wiersza
		Queue.push( s );
		s.clear();
		SetEvent( Event );
		LeaveCriticalSection( &CriticalSection );
	}

	return 0;
}

bool Console::InputQueueEmpty() {
	EnterCriticalSection( &CriticalSection );
	bool R = Queue.empty();
	LeaveCriticalSection( &CriticalSection );

	return R;
}

bool Console::GetInput( std::string *s ) {
	EnterCriticalSection( &CriticalSection );
	bool R = Queue.empty();
	if( !R ) {
		*s = Queue.front();
		Queue.pop();
		if( Queue.empty())
			ResetEvent( Event );
	}
	LeaveCriticalSection( &CriticalSection );

	return !R;
}

void Console::WaitForInput() {
	WaitForSingleObject( Event, INFINITE );
}

Console Con;

/*
void Console::Writeln( const std::string &s ) {
    SetOutputColor( FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE );

	Write( s );
	Write( "\r\n" );
}

void Console::WritelnConsole( const std::string &s ) {
    SetOutputColor( FOREGROUND_INTENSITY );

	Write( s );
	Write( "\r\n" );
}

void Console::WritelnError( const std::string &s ) {
    SetOutputColor( FOREGROUND_RED | FOREGROUND_INTENSITY );

	Write( s );
	Write( "\r\n" );
} */
