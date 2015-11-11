#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

  int pfd[2];
  if(pipe(pfd)==-1){
    printf("%s\n", "Some Error has occured");
  }
  else{
    if (fork()) {
      /* code */
      close(pfd[0]);
      char a[50];
      scanf("%s\n",a);
      write(pfd[0],a, sizeof(a));
    }
    else{
      close(pfd[1]);
      char a[50];
      read(pfd[0],a,sizeof(a));
      printf("%s\n", a);
    }
  }
  return 0;
}
