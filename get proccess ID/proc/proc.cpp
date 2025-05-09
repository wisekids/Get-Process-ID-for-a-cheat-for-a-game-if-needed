#include "proc.h"  
#include <tchar.h>  

DWORD GetProcId(const char* procName)  
{  
   DWORD procId = 0;  

   HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
   if (hSnap == INVALID_HANDLE_VALUE)  
       return procId;  

   PROCESSENTRY32 procEntry;  
   procEntry.dwSize = sizeof(PROCESSENTRY32);  

   if (Process32First(hSnap, &procEntry))  
   {  
       do  
       {  
            
           TCHAR wideProcName[MAX_PATH];  
           MultiByteToWideChar(CP_ACP, 0, procName, -1, wideProcName, MAX_PATH);  

           if (_tcscmp(procEntry.szExeFile, wideProcName) == 0)  
           {  
               procId = procEntry.th32ProcessID;  
               break;  
           }  
       } while (Process32Next(hSnap, &procEntry));  
   }  

   CloseHandle(hSnap);  
   return procId;  
}