#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "auth.h"

#define VERSION "v1.0.0"

// Funciton Prototyping
char * toLowerStr ( char * );
void insideDnsFix( void );
void helpDocumentation ( void );
void executeDnsFixingCommands ( void );
void displayCommandLineArgs ( void );
void executeCommandLineInterface (char * args);

// Driver Program
int main(int argc, char * argv[])
{
	// Funciton Prototyping
	int showMenu(void);
	void closeInteractiveSession(void);

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
			int option = showMenu();
			switch (option)
			{
				// option - 0: Exit.
				case 0:
					closeInteractiveSession();
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
					// visitSourceProject();
					puts("redirects to project url");
					break;

				// option - 5: Goto Latest Version URL.
				case 5:
					// visitLatestVersion();
					puts("redirects to project's latest release url");
					break;

				// option - 6: Displays the help documentation.
				case 6:
					helpDocumentation();
					break;

				// Other cases
				default:
					fprintf(stderr, "\033[31mError: Please select a proper option...\033[0m\n");
					fprintf(stderr, "Press Enter to continue\n");
					exit(2);
			}
		}
		else
		{
			fprintf(stderr, "\033[31mError: Please try to log in as Administrator for this program to work properly...\033[0m\n");
			fprintf(stderr, "Press Enter to continue\n");
			fflush(stdin);
			getchar();
			exit(1);
		}
		fflush(stdin);
		getchar();
	}
	return 0;
}

// Displays an interactive Menu and returns the user selected option.
int showMenu(void)
{
	int option = -1;

	printf("\n---\tWelcome to DNS Fix %s\t---\n\n",VERSION);
	puts("Please select one of the following options:");
	puts("1. Fix my DNS.");
	puts("2. View the commands used.");
	puts("3. View commandline arguments");
	puts("4. Visit this Open-Source project.");
	puts("5. Get the latest version.");
	puts("6. Help.");
	puts("0. Exit");

	printf("\nEnter you option: ");
	fflush(stdin);
	scanf("%d", &option);

	return option;
}

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

// To convert the given string into lower case.
char * toLowerStr ( char * str )
{
	for( int j = 0; j < strlen(str); ++j )
		str[j] = tolower(str[j]);
	return str;
}

// Displays the commands which this program will execute to fix the problem.
void insideDnsFix( void )
{
	puts("Following commands are executed by executing this program:\n");
	puts("\t1. ipconfig /flushdns");
	puts("\t2. ipconfig /registerdns");
	puts("\t3. ipconfig /release");
	puts("\t4. ipconfig /renew");
	puts("\t5. NETSH winsock reset catalog");
	puts("\t6. NETSH int ipv4 reset reset.log");
	puts("\t7. NETSH int ipv6 reset reset.log");
	return ;
}

// Documenting the program into -help argument.
void helpDocumentation ( void )
{
	puts("\n-------------------------------------------");
	puts("Help:");
	puts("-------------------------------------------\n");
	
	printf("Current Version: %s\n",VERSION);
	puts("Author: Shamith");
	puts("Written in: C programming Language");
	puts("Created on: 26th September 2022");
	puts("Updated on: 18th April 2023");
	puts("Required Access: Administrator");
	
	puts("\n-------------------------------------------");
	puts("Description:");
	puts("-------------------------------------------\n");
	
	puts("\"dns_fix.exe\" is a program is used to fix the \"DNS not responding problem.\" in WINDOWS OS.");
	puts("These are set of command line commands which deals with this problem even after setting their DNS server manually to the ones of the google standard one.");
	puts("If you haven\'t tried the first option, then I suggest you to try fix it that way because most of the times it fixes just by manually setting the DNS server address.");
	
	puts("\nFor more details, You can checkout this project wbesite: https://github.com/iamwatchdogs/Windows_DNS_Fixer");
	
	puts("\nNote:");
	puts("\tMake sure that this program is execute under Administrator level access, as few commands used in this program require Administrator level access.");
	puts("\tSo, to make sure that this program fulfill it purpose successfully. Run the cmd ( if you are will to execute it on cmd ) or the dns_fix.exe file as Administrator");

	puts("\nPatch Note (New Release v1.0):");
	// puts("\tWill fill at the end of the renewly");
	
	displayCommandLineArgs();
	
	return ;
}

// Displays the available options (or) acceptable arguments of this program.
void displayCommandLineArgs ( void )
{
	puts("\n-------------------------------------------\n");
	puts("Options/Arguments:");
	puts("-------------------------------------------\n");
	
	puts("For the current version, the following options (or) Arguments are supported:\n");
	puts("\t-y\t\t: To execute the program directly under the assumption that it is under Administrator level execution.\n");
	puts("\t-i\t\t: To view to commands being executed to fix the DNS problem.\n");
	puts("\t-version\t: To know the current version.\n");
	puts("\t-help\t\t: To read the following content of this program.\n");
	puts("\t-options\t: To display the available options persent in the persent version of the program.\n");
	
	puts("\n-------------------------------------------");
	return ;
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

// Displays any text in green color.
void printGreen( char * str)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("%s",str);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ;
}

// Closes the Interactive Session.
void closeInteractiveSession(void)
{
	int count = 3;
	printGreen("Closing the DNS FIX");
	while(count--)
	{
		Sleep(750);
		printGreen(".");
	}
	puts("\nPress Enter to continue\n");
	fflush(stdin);
	getchar();
	exit(0);
}
