#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

static const int SUCCESS_OF_CREATION = 0;
static const int SUCCESS_OF_JOIN = 0;

void *print(void *whois) {
    for ( int i=0; i < 10; i++) {
        printf("%s%d\n", (char*)whois, i + 1);
    }
    return EXIT_SUCCESS;
}

void *thread_action() {
    print("child ");
    return EXIT_SUCCESS;
}

int main (int  argc, char *argv[]) {
    pthread_t id_of_thread;
    int result_of_creation = pthread_create (&id_of_thread, NULL, thread_action, NULL);
    if (result_of_creation != SUCCESS_OF_CREATION) {
        perror("Thread was not created!");
        exit(EXIT_FAILURE);
    }
    int result_of_join = pthread_join (id_of_thread, NULL);
    if (result_of_join != SUCCESS_OF_JOIN) {
        perror("Thread was not joined!");
         exit(EXIT_FAILURE);
    }
    print("parent ");
    return EXIT_SUCCESS;
}
