#ifndef DISPLAY_CONTENT_H
#define DISPLAY_CONTENT_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "displayUtil.h"

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
		puts("\nPress Enter to continue\n");
		fflush(stdin);
		getchar();
	}
	exit(0);
}

// Displays an interactive Menu and returns the user selected option.
int showMenu(void)
{
	int option = -1;

	Sleep(750);

	printf("\n---\tWelcome to DNS Fix %s\t---\n\n",VERSION);
	puts("Please select one of the following options:\n");
	puts("1. Fix my DNS.");
	puts("2. View the commands used.");
	puts("3. View command line arguments.");
	puts("4. Visit this Open-Source project.");
	puts("5. Get the latest version.");
	puts("6. Help.");
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
	puts("-a (or) --args     : To display the all available argumentsof this version of the program.\n");
	puts("-c (or) --commands : To view to commands being executed to fix the DNS problem.\n");
	puts("-h (or) --help     : To read the following content of this program.\n");
	puts("-p (or) --project  : Redirects to the Original Open-Source Project.\n");
	puts("-u (or) --update   : Redirects to the releases of this Project.\n");
	puts("-v (or) --version  : To know the current version.\n");
	
	puts("\n-------------------------------------------------------------------------------------------");
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
	
	printf("\"dns_fix.exe\" is a program is used to fix the \"DNS not responding problem.\" in WINDOWS OS.");
	printf("These are set of command line commands which deals with this problem even after setting their DNS server manually to the ones of the google standard one.");
	puts("If you haven\'t tried the first option, then I suggest you to try fix it that way because most of the times it fixes just by manually setting the DNS server address.");
	
	puts("\nFor more details, You can checkout this project website: https://github.com/iamwatchdogs/Windows_DNS_Fixer");
	
	puts("\nNote:");
	printf("Make sure that this program is execute under Administrator level access, as some the commands used in this program require Administrator level access.");
	puts("So, to make sure that this program fulfill it purpose successfully. Run the cmd ( if you are will to execute it on cmd ) or the dns_fix.exe file as Administrator");

    insideDnsFix();
    
	displayCommandLineArgs();

    puts("\n-------------------------------------------");
	printf("\nPatch Note (New Release %s):\n",VERSION);
    puts("-------------------------------------------\n");
	// puts("\tWill fill at the end of the renewly");
	
	return ;
}

#endif