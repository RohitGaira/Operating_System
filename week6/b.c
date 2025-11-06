#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
};
int main() {
    struct msg_buffer message;
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (fork() == 0) {
        message.msg_type = 1;
        printf("Child: Enter message for parent: ");
        fgets(message.msg_text, MAX, stdin);
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Child: Message sent to parent.\n");
    } 
    else {
        sleep(2); 
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Parent: Message received from child: %s", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0; }
