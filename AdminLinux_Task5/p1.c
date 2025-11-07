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

    printf("Chat started. You send first...\n");
    while (1) {
        // P1's turn to send
        if (shm[0] == 0 || shm[0] == 2) {
            printf("[1 -> 2]: ");
            fgets(shm + 1, SIZE - 1, stdin);
            shm[0] = 1;  // message ready for p2
        }

        // Wait for P2's response
        while (shm[0] != 2) {
            usleep(100000);
        }
        printf("[2 -> 1]: %s", shm + 1);
        shm[0] = 0;  // mark as read
    }

    shmdt(shm);
    return 0;
}
