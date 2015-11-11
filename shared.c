#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
  int size=1024;
  int segment=shmget(IPC_PRIVATE,size,S_IRUSR|S_IWUSR);
  char* shared_memory=(char*)shmat(segment,NULL,0);
  sprintf(shared_memory,"Shared memory");
  puts(shared_memory);
  shmdt(shared_memory);
  shmctl(segment,IPC_RMID,NULL);
  return 0;
}
