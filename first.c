#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fdr,fdw;
  fdr=open("One.txt",O_CREAT|O_RDWR,777);
  fdw=open("Two.txt",O_CREAT|O_RDWR,777);

  char buff[1024];
  if (fdr != -1 && fdw !=-1) {
    int r=read(fdr,buff,1024);
    if (r!=-1) {
      int w=write(fdw,buff,r);
    }
  }
  close(fdr);
  close(fdw);
  return 0;

}
