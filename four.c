#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char buf[1024];
	int fdr = open("test/One.txt", O_CREAT|O_RDWR, 777);
	int fdw = open("test/two.txt", O_CREAT|O_RDWR, 777);
	if(fdr!=-1 && fdw!=-1)
	{
		lseek(fdr, 100, SEEK_SET);
		int r = read(fdr,buf,1024);
		if(r!=-1)
		{
			int w = write(fdw,buf,r-100);
			printf("Error A %d\n", w);
		}
		printf("Error B %d\n",r);
	}
	printf("Error C %d %d\n",fdr,fdw);
	close(fdr);
	close(fdw);
	return 0;
}
