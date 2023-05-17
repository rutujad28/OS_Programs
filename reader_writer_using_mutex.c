#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for the first readers-writers problem using mutex and semaphore.
I have used 10 readers and 5 writers to demonstrate the solution. You can modify these values as per your requirement.
*/

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numreader = 0;

void *writer(void *wno)
{
    while (1) {
        sem_wait(&wrt);
        cnt = cnt * 2;
        printf("Writer %d modified cnt to %d\n", *((int *)wno), cnt);
        sem_post(&wrt);
        break;
    }
}

void *reader(void *rno)
{
    while (1) {
        pthread_mutex_lock(&mutex);
        numreader++;
        if (numreader == 1) {
            sem_wait(&wrt); // If this is the first reader, block the writer
        }
        pthread_mutex_unlock(&mutex);

        // Reading Section
        printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

        pthread_mutex_lock(&mutex);
        numreader--;
        if (numreader == 0) {
            sem_post(&wrt); // If this is the last reader, wake up the writer
        }
        pthread_mutex_unlock(&mutex);
        break;
    }
}

int main()
{
    pthread_t read[10], write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Used for numbering the readers and writers

    for (int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, reader, &a[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, writer, &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}