#include "../proc/proc.h"
#include <iostream>

int main()
{
	const char* procName = "Enter a procName";

	DWORD procId = GetProcId(procName);


	if (procId == 0)
	{
		std::cout << "Enter a process name for it to work.";
		Sleep(5000);
		exit(0);
	}
	else
	{
		std::cout << "Your Proccess ID is : " << procId << std::endl;
		Sleep(5000);
		exit(0);
	}
}