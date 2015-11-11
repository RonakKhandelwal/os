#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>


// int main(){
//   char buf[1024];
//   DIR *fdr=opendir("test");
//   dirent *dir=readdir(fdr);
//   while(dir != NULL){
//     printf("%s\n", dir->d_name);
//     dir=readdir(fdr);
//   }
//   return 0;
//
//
//
// }



int main()
{
	char buf[1024];
	DIR *fdr = opendir("test");
	dirent *dir = readdir(fdr);
	while(dir!=NULL)
	{
		printf("%s\n",dir->d_name);
		dir = readdir(fdr);
	}
	closedir(fdr);
	return 0;
}
