#ifndef HEADER_FILES_EXECUTIONENGINE
#define HEADER_FILES_EXECUTIONENGINE

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "displayUtil.h"
#include "displayContent.h"

#define VERSION "v1.0.0"

#endif

// The main DNS problem fixing commands.
void executeDnsFixingCommands ( void )
{
	system("cls");
	system("ipconfig /flushdns");
	Sleep(300);
	system("ipconfig /registerdns");
	Sleep(800);
	system("ipconfig /release");
	Sleep(600);
	system("ipconfig /renew");
	Sleep(1200);
	system("NETSH winsock reset catalog");
	Sleep(1700);
	system("NETSH int ipv4 reset reset.log");
	Sleep(300);
	system("NETSH int ipv6 reset reset.log");
	Sleep(300);
	puts("-------------------------------------------");
	puts("\nRestart you system now...\n");
	puts("-------------------------------------------");
	fflush(stdin);
	getchar();
}

void redirectSourceProject(void) 
{
	int count = 3;
	printGreen("\nRedirecting to Original Open-Source Project");
	while(count--)
	{
		Sleep(175);
		printGreen(".");
	}
	system("start https://github.com/iamwatchdogs/Windows_DNS_Fixer");
	closeInteractiveSession(TRUE);
}

void redirectLatestVersion(void)
{
	int count = 3;
	printf("\nCurrent Version is %s",VERSION);
	Sleep(800);
	puts("\nPlease Check for even higher vesion...");
	Sleep(1200);
	printGreen("\nRedirecting to Original Open-Source Project");
	while(count--)
	{
		Sleep(175);
		printGreen(".");
	}
	puts("\n");
	Sleep(585);
	system("start https://github.com/iamwatchdogs/Windows_DNS_Fixer/releases");
	closeInteractiveSession(TRUE);
}

void optionExecutor (int option)
{
	BOOL quickExit = FALSE;
	switch (option)
	{
		// option - 0: Exit.
		case 0:
			break;

		// option - 1: Fixes DNS.
		case 1:
			// executeDnsFixingCommands();
			puts("executes the DNS commands");
			break;

				// option - 2: Displays the commands.
		case 2:
			insideDnsFix();
			break;

				// option - 3: Displays the commandline arguments.
		case 3:
			displayCommandLineArgs();
			break;

				// option - 4: Goto Project URL.
		case 4:
			redirectSourceProject();
			quickExit = TRUE;
			break;

				// option - 5: Goto Latest Version URL.
		case 5:
			redirectLatestVersion();
			quickExit = TRUE;
			break;

		// option - 6: Displays the help documentation.
		case 6:
			helpDocumentation();
			break;

		// Other cases
		default:
			printError("\nError: Please select a proper option...\n");
			puts("Press Enter to continue\n");
			fflush(stdin);
			getchar();
			exit(2);
	}

	closeInteractiveSession(quickExit);
}

// When user uses command line to execute the program ( args are arrange in alphabetical order ).
void executeCommandLineInterface (char * args)
{
	// Displays the commands used to resolve the DNS problem.
	if( !strcmp(toLowerStr(args),"-i" ) )
	{
		insideDnsFix();
	}
	
	// To execute the program directly without asking to verify whether it's gonna execute in -
	// - Administrator mode or not.
	else if( !strcmp(toLowerStr(args),"-y") )
	{
		puts("\n-------------------------------------------");
		puts("Note:");
		puts("-------------------------------------------");
		puts("The program is being execute assuming that it is in Administrator mode...");
		Sleep(1500);
		executeDnsFixingCommands();
	}
	
	// Displays the documentation of this program.
	else if( !strcmp(toLowerStr(args),"-help"))
	{
		helpDocumentation();
	}
	
	// To display available options (or) arguments in this program.
	else if( !strcmp(toLowerStr(args),"-options"))
	{
		displayCommandLineArgs();
	}
	
	// Displays the version of this program.
	else if( !strcmp(toLowerStr(args),"-version" ) )
	{
		printf("\ndns_fix.exe version %s\n",VERSION);
	}
	
	// Default case of undefined/declined argument
	else
	{
		printf("Invalid Argument : \"%s\"\n",args);
		puts("Try again with an different argument...");
		fflush(stdin);
		getchar();
		exit(2);
	}
	
	return ;
}