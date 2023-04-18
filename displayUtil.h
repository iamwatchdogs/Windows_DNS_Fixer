#ifndef HEADER_FILES_DISPLAYUTIL
#define HEADER_FILES_DISPLAYUTIL

#include <stdio.h>
#include <string.h>
#include <windows.h>

#endif

// Displays any text in green color.
void printGreen( char * str)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("%s",str);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ;
}

// Displays any error messages in red color.
void printError( char * str)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	fprintf(stderr, str);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ;
}

// To convert the given string into lower case.
char * toLowerStr ( char * str )
{
	for( int j = 0; j < strlen(str); ++j )
		str[j] = tolower(str[j]);
	return str;
}