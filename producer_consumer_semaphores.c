#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BUFFER_SIZE 10
#define MAX_ITEMS 100

int buffer[MAX_BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;
int items_produced = 0;
int items_consumed = 0;

sem_t empty;    // semaphore to track empty slots in buffer
sem_t full;     // semaphore to track filled slots in buffer

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;    // generate a random item to add to buffer
        sem_wait(&empty);       // wait for an empty slot in buffer
        buffer[in] = item;      // add item to buffer
        in = (in + 1) % MAX_BUFFER_SIZE; // increment in pointer
        count++;                // increment item count
        items_produced++;       // increment items produced count
        printf("Produced item: %d\n", item);
        sem_post(&full);        // signal that a slot is now filled
        if (items_produced == MAX_ITEMS) {
            break;              // exit loop if all items have been produced
        }
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);        // wait for a filled slot in buffer
        item = buffer[out];     // remove item from buffer
        out = (out + 1) % MAX_BUFFER_SIZE; // increment out pointer
        count--;                // decrement item count
        items_consumed++;       // increment items consumed count
        printf("Consumed item: %d\n", item);
        sem_post(&empty);       // signal that a slot is now empty
        if (items_consumed == MAX_ITEMS) {
            break;              // exit loop if all items have been consumed
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod_tid, cons_tid;

    // initialize semaphores
    sem_init(&empty, 0, MAX_BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // create producer and consumer threads
    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);

    // wait for threads to complete
    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    // destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}