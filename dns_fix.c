#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Funciton Prototyping
char * to_lower_str ( char * );
void inside_dns_fix( void );
void help_documentation ( void );
void dns_fixing_commands ( void );
void display_options ( void );
void command_line_interface (char * args);

// Driver Program
int main(int argc, char * argv[])
{
	// If the user is executing through command line interface.
	if( argc > 1 )
	{
		command_line_interface( argv[1] );
	}
	
	// If the user is running the .exe file directly.
	else
	{
		char c;
		puts("---\tInteractive Session\t---");
		printf("Have you logged in as Administrator (Y/N) ? ");
		fflush(stdin);
		scanf("%c",&c);
		if( c == 'y' || c == 'Y' )
		{
			dns_fixing_commands();
		}
		else if  ( c == 'n' || c == 'N' )
		{
			fprintf(stderr, "Error: Please try to log in as Administrator for this program to work properly...\n");
			fprintf(stderr, "Press Enter to continue\n");
			fflush(stdin);
			getchar();
			exit(1);
		}
		else 
		{
			fprintf(stderr, "Error: Invalid Input...\n");
			fprintf(stderr, "Press Enter to continue\n");
			fflush(stdin);
			getchar();
			exit(-1);
		}
	}
	return 0;
}

// The main DNS problem fixing commands.
void dns_fixing_commands ( void )
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
char * to_lower_str ( char * str )
{
	for( int j = 0; j < strlen(str); ++j )
		str[j] = tolower(str[j]);
	return str;
}

// Displays the commands which this program will execute to fix the problem.
void inside_dns_fix( void )
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
void help_documentation ( void )
{
	puts("\n-------------------------------------------");
	puts("Help:");
	puts("-------------------------------------------\n");
	
	puts("Current Version: v1.0.0");
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
	
	puts("For more details, You can checkout this project wbesite: https://github.com/iamwatchdogs/Windows_DNS_Fixer");
	
	puts("\nNote:");
	puts("\tMake sure that this program is execute under Administrator level access, as few commands used in this program require Administrator level access.");
	puts("\tSo, to make sure that this program fulfill it purpose successfully. Run the cmd ( if you are will to execute it on cmd ) or the dns_fix.exe file as Administrator");

	puts("\nPatch Note (New Release v1.0):");
	// puts("\tWill fill at the end of the renewly");
	
	display_options();
	
	return ;
}

// Displays the available options (or) acceptable arguments of this program.
void display_options ( void )
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
void command_line_interface (char * args)
{
	// Displays the commands used to resolve the DNS problem.
	if( !strcmp(to_lower_str(args),"-i" ) )
	{
		inside_dns_fix();
	}
	
	// To execute the program directly without asking to verify whether it's gonna execute in -
	// - Administrator mode or not.
	else if( !strcmp(to_lower_str(args),"-y") )
	{
		puts("\n-------------------------------------------");
		puts("Note:");
		puts("-------------------------------------------");
		puts("The program is being execute assuming that it is in Administrator mode...");
		Sleep(1500);
		dns_fixing_commands();
	}
	
	// Displays the documentation of this program.
	else if( !strcmp(to_lower_str(args),"-help"))
	{
		help_documentation();
	}
	
	// To display available options (or) arguments in this program.
	else if( !strcmp(to_lower_str(args),"-options"))
	{
		display_options();
	}
	
	// Displays the version of this program.
	else if( !strcmp(to_lower_str(args),"-version" ) )
	{
		puts("\ndns_fix.exe version 1.0.0v");
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
