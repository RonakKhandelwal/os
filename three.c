#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){


  int v= fork();

  if (v == 0) {
    printf("%s\n", "Child process");
    printf("process id :: %d \t parent process id :: %d\n",getpid(),getppid() );
  }
  else if (v < 0) {
    printf("%s\n", "Some error has occured");
  }
  else
  {
    printf("%s\n", "Parent process here");
    printf("process id :: %d \t parent process id :: %d\n",getpid(),getppid() );
    printf("%s\t%d\n","Btw the child id should be",v );

  }  


  return 0;
}
