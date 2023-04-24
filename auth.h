#ifndef AUTH_H
#define AUTH_H

#include <stdio.h>
#include <windows.h>
#include <sddl.h>

#include "displayUtil.h"

// Uses Windows API to determine if your program is running with administrative privileges.
BOOL isElevated(void)
{
    HANDLE hToken = NULL;
    TOKEN_ELEVATION elevation = {0};
    DWORD size = 0;

    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
    {
        return FALSE;
    }

    if (!GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &size))
    {
        CloseHandle(hToken);
        return FALSE;
    }

    CloseHandle(hToken);

    return elevation.TokenIsElevated;
}

// Checks whether this program is executed as Administrator or not.
BOOL isExecutedAsAdmin(void)
{
	int count = 3;
    Sleep(250);
	puts("\nThis program requires Administrative Access !!!...");
	printf("Checking for Administrative privileges");
	while(count--){
		Sleep(250);
		printf(".");
	}
	return isElevated();
}

// Prompts the user to re-run the program as Administrator.
void promptForAdmin(void) 
{
    TCHAR szPath[MAX_PATH];
    if (GetModuleFileName(NULL, szPath, MAX_PATH)) 
    {
        SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = TEXT("runas");
        sei.lpFile = szPath;
        sei.lpParameters = "-dr";
        sei.nShow = SW_NORMAL;

        // Execution and Error message handling
        if (!ShellExecuteEx(&sei)) 
        {
            DWORD error = GetLastError();
            if (error == ERROR_CANCELLED)
            {
                // User canceled UAC prompt
                printError("Error: End-User canceled UAC prompt.\n");
                fflush(stdin);
                getchar();
            } 
            else 
            {
                // Prints the other possible error message
                errorPromptForAdminAccess(error);
            }
        }
    }
}

#endif