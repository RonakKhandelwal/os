#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pfd1[2], pfd2[2];
	float num,buf;
	if(pipe(pfd1)==-1)
	{
		printf("Error\n");
	}
	if(pipe(pfd2)==-1)
	{
		printf("Error\n");
	}
	else
	{
		if(fork())
		{
			close(pfd1[0]);
			char t[10];
			scanf("%f",&num);
			write(pfd1[1],&num,sizeof(num));
			close(pfd2[1]);
			read(pfd2[0],&buf,50);
			printf("%f\n",buf);
			wait(NULL);
		}
		else
		{
			close(pfd1[1]);
			char t[10];
			read(pfd1[0],&buf,50);
			num = sqrt(buf);
			close(pfd2[0]);
			write(pfd2[1],&num,sizeof(num));
		}
	}
}
