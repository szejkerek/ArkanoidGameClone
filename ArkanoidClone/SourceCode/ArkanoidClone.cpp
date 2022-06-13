#include "Program.h"
#include <Windows.h>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	//3620
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Memory leaks check
	Program program;
	program.Run();
}
