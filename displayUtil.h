// Checking for repeation
#ifndef DISPLAY_UTIL_H
#define DISPLAY_UTIL_H

#include <stdio.h>
#include <string.h>
#include <windows.h>

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

// Prints given character at given number of time with given time gap.
void customPrintChar (char c, int times, int timeGap)
{
	while(times--)
	{
		Sleep(timeGap);
		printf("%c", c);
	}
	return ;
}

// Resets the printed characters, so that they could be replaced.
	void resetPrintedChar (int spaces)
	{
		customPrintChar('\b', spaces, 0);
		customPrintChar(' ', spaces, 0);
		customPrintChar('\b', spaces, 0);
		return;
	}

// Displays the start up message for Interactive Session.
void displayStartUpMessage(void)
{
    int iter = 2;
	int count = 3;
	int dotTimeGap = 200, resetTimeGap = 100;
	printf("\nRunning an Interactive Session");
	while (iter--)
	{
		customPrintChar('.', count, dotTimeGap);
		Sleep(resetTimeGap);
	    resetPrintedChar(count);
	}
	customPrintChar('.', count, dotTimeGap/2);
	Sleep(resetTimeGap/2);
	puts("\n");
	return ;
}

// Prints the respective error message
void errorPromptForAdminAccess(DWORD error)
{
    TCHAR errorMessage[256];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, 0, errorMessage, sizeof(errorMessage), NULL);
    puts("\n");
	printError((char *)errorMessage);
    printError((char *)errorMessage);
    printf("\n");
    fflush(stdin);
    getchar();
    return ;
}

#endif