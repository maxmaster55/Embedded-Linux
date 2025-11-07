#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define KEY 0xDeadBeef
#define SIZE 512

int main() {
    int shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat failed");
        return 1;
    }

    printf("Chat started. Waiting for p1...\n");

    while (1) {
        // Wait for P1's message
        while (shm[0] != 1) {
            usleep(100000);
        }
        printf("[1 -> 2]: %s", shm + 1);
        
        // P2's turn to respond
        printf("[2 -> 1]: ");
        fgets(shm + 1, SIZE - 1, stdin);
        shm[0] = 2;  // message ready for p1
    }

    shmdt(shm);
    return 0;
}
