#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
    int size=1024;
    int segid1 = shmget((key_t)11111,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int segid2 = shmget((key_t)11112,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int segid3 = shmget((key_t)11113,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int *sm1 = (int *) shmat(segid1,NULL,0);
    int *sm2 = (int *) shmat(segid2,NULL,0);
    int *sm3 = (int *) shmat(segid3,NULL,0);
    while(1)
        if(sm3!=NULL && sm1!=NULL && sm2!=NULL)
            *sm3=*sm1+*sm2;
    shmdt(sm1);
    shmdt(sm2);
    shmdt(sm3);
    shmctl(segid1,IPC_RMID,NULL);
    shmctl(segid2,IPC_RMID,NULL);
    shmctl(segid3,IPC_RMID,NULL);
}
