#include <stdio.h>
#include <stdlib.h>

// Version of the program
#define VERSION "v1.0.0"

// User-defined Header files
#include "auth.h"
#include "displayUtil.h"
#include "displayContent.h"
#include "executionEngine.h"

// Driver Program
int main(int argc, char * argv[])
{

	// Function Prototypes
 	void displayStartUpMessage(void);

	// If the user is executing through command line interface and has passed more than 1 argument value.
	if( argc > 2 )
	{
		printError("\nError: Too many argument passed, Please try again...\n");
		puts("Press Enter to continue");
		fflush(stdin);
		getchar();
		exit(1);
	}

	// If the user is executing through command line interface and sent single argument.
	else if ( argc == 2 )
	{
		executeCommandLineInterface( argv[1] );
	}

	// If the user is running the .exe file directly.
	else
	{
		displayStartUpMessage();
		int option = showMenu();
		optionExecutor(option);
		fflush(stdin);
		getchar();
	}

	return 0;
}