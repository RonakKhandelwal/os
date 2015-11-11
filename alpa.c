#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc,char *argv[])
{
    char *shared_memory;
    int size=1024;
    int segment_id = shmget(IPC_PRIVATE,size,S_IRUSR|S_IWUSR);
    shared_memory = (char *) shmat(segment_id,NULL,0);
    if(fork())
    {
        sprintf(shared_memory,"%s",argv[1]);
        wait(NULL);
        puts(shared_memory);
    }
    else
    {
        shared_memory[0]++;
    }
    shmdt(shared_memory);
    shmctl(segment_id,IPC_RMID,NULL);
    return 0;
}
