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
    int a1[2][2],a2[2][2],sum[2][2];
    int a;
    int b;
    int size=1024;
    int segid1 = shmget((key_t)11111,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int segid2 = shmget((key_t)11112,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int segid3 = shmget((key_t)11113,size,IPC_CREAT|S_IRUSR|S_IWUSR);
    int *sm1 = (int *) shmat(segid1,NULL,0);
    int *sm2 = (int *) shmat(segid2,NULL,0);
    int *sm3 = (int *) shmat(segid3,NULL,0);


  scanf("%d",&a);


    scanf("%d",&b);
    printf("Calculating Sum\n");
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         *sm1=a1[i][j]; // Write number of 1st array
    //         *sm2=a2[i][j]; // Write number of 2nd array
    //         sleep(1);
    //         sum[i][j]=*sm3; // Get sum from SM
    //     }
    // }
    *sm1=a;
    *sm2=b;
    sleep(1);
    int c;
    c=*sm3;
    printf("%d\n",c );
    shmdt(sm1);
    shmdt(sm2);
    shmdt(sm3);
}
