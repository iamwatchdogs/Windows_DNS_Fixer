#ifndef EXECUTION_ENGINE_H
#define EXECUTION_ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "auth.h"
#include "displayUtil.h"
#include "displayContent.h"

#ifndef VERSION
#define VERSION NULL
#endif


// The main DNS problem fixing commands.
void executeDnsFixingCommands ( void )
{
	int countDown = 5, timeGap = 1000;
	// puts("\n---\tExecuting the DNS Fixing Commands\t---\n");
	// Sleep(300);
	// system("ipconfig /flushdns");
	// Sleep(300);
	// system("ipconfig /registerdns");
	// Sleep(800);
	// system("ipconfig /release");
	// Sleep(600);
	// system("ipconfig /renew");
	// Sleep(1200);
	// system("NETSH winsock reset catalog");
	// Sleep(1700);
	// system("NETSH int ipv4 reset reset.log");
	// Sleep(300);
	// system("NETSH int ipv6 reset reset.log");
	Sleep(300);
	printf("\n\n");
	while (countDown--)
	{
		system("cls");
		printf("Restarting your system now in %d.", countDown+1);
		Sleep(timeGap);
	}
	// system("shutdown /r /t 1");
	return ;
}

// Redirects to the original Open-Source project.
void redirectSourceProject(void) 
{
	int count = 3;
	printGreen("\nRedirecting to Original Open-Source Project");
	while(count--)
	{
		Sleep(175);
		printGreen(".");
	}
	printf("\n");
	system("start https://github.com/iamwatchdogs/Windows_DNS_Fixer");
}

// Redirects to the latest release of this program.
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
	printf("\n");
	Sleep(585);
	system("start https://github.com/iamwatchdogs/Windows_DNS_Fixer/releases");
}

// Checks for administrative privileges and executes the DNS Fixing commands
void checkAndExecute(void)
{	
	BOOL hasAdminAccess = isExecutedAsAdmin();
	if( hasAdminAccess )
	{
		int count = 3;
		printGreen("\nHas Administrative access");
		while(count--)
		{
			Sleep(175);
			printGreen(".");
		}
		printf("\n");
		executeDnsFixingCommands();
	}
	else
	{
		printError("\n\nError: Not logged in as Administrator.\n");
		Sleep(300);
		printf("Press Enter to relaunch as Administrator.");
		fflush(stdin);
		getchar();
		promptForAdmin();
		exit(1);
	}
	return ;
}

// Evaluates the user given option and executes the following command.
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
		    checkAndExecute();
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
	BOOL quickExit = FALSE;

	// To display available options (or) arguments in this program.
	if( !strcmp(toLowerStr(args),"-a") || !strcmp(toLowerStr(args),"--args") )
	{
		puts("\n---\tRunning an Command Line Session\t---\t\n");
		displayCommandLineArgs();
	}

	// Displays the commands used to resolve the DNS problem.
	else if( !strcmp(toLowerStr(args),"-c" ) || !strcmp(toLowerStr(args),"--commands") )
	{
		puts("\n---\tRunning an Command Line Session\t---\t\n");
		insideDnsFix();
	}
	
	// Displays the documentation of this program.
	else if( !strcmp(toLowerStr(args),"-h") || !strcmp(toLowerStr(args),"--help") )
	{
		puts("\n---\tRunning an Command Line Session\t---\t\n");
		helpDocumentation();
	}

	// Redirects to Original Open-Source project
	else if( !strcmp(toLowerStr(args),"-p") || !strcmp(toLowerStr(args),"--project") )
	{
		redirectSourceProject();
		quickExit = TRUE;
	}

	// Runs the DNS resolving commands after checking for administrative privileges.
	else if( !strcmp(toLowerStr(args),"-r") || !strcmp(toLowerStr(args),"--run") )
	{
		puts("\n---\tRunning an Command Line Session\t---\t\n");
		checkAndExecute();
	}

	// Redirects to Releases Open-Source project
	else if( !strcmp(toLowerStr(args),"-u") || !strcmp(toLowerStr(args),"--update") )
	{
		redirectLatestVersion();
		quickExit = TRUE;
	}
	
	// Displays the version of this program.
	else if( !strcmp(toLowerStr(args),"-v" ) || !strcmp(toLowerStr(args),"--version") )
	{
		printf("\nCurrent Version of dns_fix: %s\n",VERSION);
		quickExit = TRUE;
	}
	
	// Default case of undefined/declined argument
	else
	{
		printError("\n\nError: Invalid Argument.\nTry again with an different argument...\n");
		puts("Press Enter to continue\n");
		fflush(stdin);
		getchar();
		exit(2);
	}
	
	closeInteractiveSession(quickExit);
}

#endif