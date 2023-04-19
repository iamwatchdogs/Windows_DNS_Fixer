#ifndef AUTH_H
#define AUTH_H

#include <stdio.h>
#include <windows.h>
#include <sddl.h>

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

#endif
