#include <windows.h>

int main()
{
	char cmd[] = "CONTROL.EXE main.cpl @0";
	system(cmd);
	return 0;
}
