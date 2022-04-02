#include "Program.h"

//memory leaks check
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//

int main()
{
	
	{
		Program program;
		program.Run();
	}
	
	_CrtDumpMemoryLeaks();
}
