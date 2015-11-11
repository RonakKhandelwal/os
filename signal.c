#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void hanlder(int signum)
{
	printf("Terminated and Handled %d",signum);
	exit(0);
}

int main()
{
	signal(SIGINT,hanlder);
	while(1)
		printf("Infinite loop, press CTRL+C to terminate\n");
	return 0;
}
