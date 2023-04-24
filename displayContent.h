#ifndef DISPLAY_CONTENT_H
#define DISPLAY_CONTENT_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "displayUtil.h"

#ifndef VERSION
#define VERSION NULL
#endif

// Closes the Interactive Session.
void closeInteractiveSession(BOOL quickClose)
{
	int count = 3;
	printGreen("\nClosing the DNS FIX");
	while(count--)
	{
		Sleep(250);
		printGreen(".");
	}
	if(!quickClose)
	{
		puts("\nPress Enter to continue");
		fflush(stdin);
		getchar();
	}
	else
	{
		printf("\n");
	}
	printf("\n");
	exit(0);
}

// Displays an interactive Menu and returns the user selected option.
int showMenu(void)
{
	int option = -1;

	Sleep(500);
	system("cls");

	printf("---\tWelcome to DNS Fix %s\t---\n\n",VERSION);
	puts("Please select one of the following options:\n");
	puts("1. Fix my DNS.");
	puts("2. View the commands used.");
	puts("3. View command line arguments.");
	puts("4. Visit this Open-Source project.");
	puts("5. Get the latest version.");
	puts("6. View the patch notes.");
	puts("7. Help.");
	puts("0. Exit");

	printf("\nEnter you option: ");
	fflush(stdin);
	scanf("%d", &option);

	return option;
}

// Displays the commands which this program will execute to fix the problem.
void insideDnsFix( void )
{
	puts("\nFollowing commands are executed by executing this program:\n");
	puts("\t1. ipconfig /flushdns");
	puts("\t2. ipconfig /registerdns");
	puts("\t3. ipconfig /release");
	puts("\t4. ipconfig /renew");
	puts("\t5. NETSH winsock reset catalog");
	puts("\t6. NETSH int ipv4 reset reset.log");
	puts("\t7. NETSH int ipv6 reset reset.log");
	return ;
}

// Displays the available options (or) acceptable arguments of this program.
void displayCommandLineArgs ( void )
{
	puts("\n-------------------------------------------------------------------------------------------\n");
	puts("Options/Arguments:");
	puts("-------------------------------------------------------------------------------------------\n");
	
	puts("For the current version, the following options (or) Arguments are supported:\n");
	puts("-a  (or) --args       : To display the all available argumentsof this version of the program.\n");
	puts("-c  (or) --commands   : To view to commands being executed to fix the DNS problem.\n");
	puts("-dr (or) --directrun  : Directly runs the DNS fixing commands without Admin check. (Not Recommended for end-users)");
	puts("-h  (or) --help       : To read the following content of this program.\n");
	puts("-p  (or) --project    : Redirects to the Original Open-Source Project.\n");
	puts("-pn (or) --patchnotes : Runs the commands to fix the DNS issue.\n");
	puts("-r  (or) --run        : Runs the commands to fix the DNS issue.\n");
	puts("-u  (or) --update     : Redirects to the releases of this Project.\n");
	puts("-v  (or) --version    : To know the current version.\n");
	
	puts("\n-------------------------------------------------------------------------------------------");
	return ;
}

void displayPatchNotes ( void )
{
    puts("\n-------------------------------------------");
	printf("\nPatch Note (New Release %s):\n",VERSION);
    puts("-------------------------------------------\n");
	puts("* Completely reworked on the pervious version of orginal source code for this project.");
	puts("* Updated commandline arguments for better interaction.");
	puts("* Improved end-user interaction through Interactive and CommandLine sessions.");
	puts("* Implemented the auto-check for admin access for executing DNS fixing commands.");
	puts("* Implemented auto-relaunch to execute the commands after seeking end-user\'s permission.");
	puts("* Implemented Error-prompting for debugging this utility program.");
	puts("* Added Source to redirect the program to the original project.");
	puts("* Added Source to redirect the program to check for latest releases.");
	puts("* Improved Documentation.");
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
	puts("Operating System: Windows 10 or above");
	
	puts("\n-------------------------------------------");
	puts("Description:");
	puts("-------------------------------------------\n");
	
	printf("\"dns_fix.exe\" is a program is used to fix the \"DNS not responding problem.\" in WINDOWS OS.");
	printf("These are set of command line commands which deals with this problem even after setting their DNS server manually to the ones of the google standard one.");
	puts("If you haven\'t tried the first option, then I suggest you to try fix it that way because most of the times it fixes just by manually setting the DNS server address.");
	puts("\nTry to find these steps in my original project, you can directly redirect to the project using \'-p\' or \'--project\' arguments.\n");
	
	insideDnsFix();
    
	displayCommandLineArgs();

	puts("\nNote:");
	puts("- Please try to use this untility program if and only if you're facing DNS issue even after following basic troubleshooting steps.");
	puts("- Some of the commands require Adminstrator Access for executing the DNS issue resolving commands.");
	puts("- Please try to avoid using \"-dr\" or \"--directrun\" arguments, as they execute the commands without checking for Admin access.");
	puts("- Never use \"-dr\" or \"--directrun\" arguments, if you don't know what you\'re doing.");
	puts("- The direct run option is purposefully not included in Interactive Session for security reasons.");
	puts("- If you're a begineer who want to learn & understand, then you can checkout orginal project.");

    displayPatchNotes();
	
	puts("\nFor more details, You can checkout this project website: https://github.com/iamwatchdogs/Windows_DNS_Fixer");

	return ;
}

#endif