#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Version of the program
#define VERSION "v1.0.0"

// User-defined Header files
#include "auth.h"
#include "displayUtil.h"
#include "displayContent.h"
#include "executionEngine.h"

// Funciton Prototyping
void executeDnsFixingCommands ( void );
void executeCommandLineInterface (char * args);

// Driver Program
int main(int argc, char * argv[])
{
	// Funciton Prototyping
	int showMenu(void);
	void redirectSourceProject(void);
	void redirectLatestVersion(void);
	void optionExecutor (int option);

	// If the user is executing through command line interface.
	if( argc > 1 )
	{
		executeCommandLineInterface( argv[1] );
	}

	// If the user is running the .exe file directly.
	else
	{
		puts("\n---\tRunning an Interactive Session\t---\t\n");
		BOOL hasAdminAccess = isExecutedAsAdmin();
		if( hasAdminAccess )
		{
			printGreen("\nHas Administrative access.\n");
			int option = showMenu();
			optionExecutor(option);
		}
		else
		{
			printError("\n\nError: Please try to log in as Administrator for this program to work properly...\n");
			puts("Press Enter to continue\n");
			fflush(stdin);
			getchar();
			exit(1);
		}
		fflush(stdin);
		getchar();
	}
	return 0;
}
