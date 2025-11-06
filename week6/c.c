#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() 
{
    key_t key = ftok("shmfile", 65); 
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
    char *str = (char*) shmat(shmid, NULL, 0);       
    if (fork() == 0) {
        printf("Child: Enter some text for parent: ");
        fgets(str, 1024, stdin);
        printf("Child: Data written to shared memory.\n");} 
    else {
        wait(NULL); 
        printf("Parent: Data read from shared memory: %s", str);
        shmdt(str);                 
        shmctl(shmid, IPC_RMID, 0);   }
    return 0;
}



