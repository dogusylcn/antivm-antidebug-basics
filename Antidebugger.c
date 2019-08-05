#include<windows.h>
#include<stdio.h>

int main() 
{
	register int eax asm("%eax");
	OutputDebugString("Tubitak");// this changes eax value when program works in debugger
	
	if(eax>1) 
		{
			printf("debugger detected");
			return 0;
		
		}

	if(IsDebuggerPresent()) // windows api 
		{
			printf("debugger detected");
			return 0;
		}

	int count = GetTickCount(); // get time from timer, miliseconds type 
	int count2 = GetTickCount();
	printf("Tick Count 2 = %d\n",count);
	printf("Tick Count 1 = %d\n",count2);

	if(count == count2) // we can say there is no debugger if timer counts are equals
		{
			printf("No debugger detected");
		}
	else printf("debuger detected");	

        return 0;
}
