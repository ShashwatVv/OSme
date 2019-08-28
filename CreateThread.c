#include<stdio.h>
#include<windows.h>

int main(VOID)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    if(!CreateProcess(NULL, "C:\\Users\\Shashwat\\Documents\\ChordUke\\main.exe" ,
                      NULL, NULL, FALSE, 0,
                       NULL, NULL, &si, &pi))
       {
           fprintf(stderr, "Create Process Failed");
           return -1;
       }
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
