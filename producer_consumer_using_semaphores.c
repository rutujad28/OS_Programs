/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int buffer_index;
sem_t full_sem, empty_sem, buffer_sem;

void *producer(void *arg) {
    int i, item;
    for (i = 0; i < 20; i++) {
        item = rand() % 100; // Produce a random item
        sem_wait(&empty_sem); // Wait for an empty slot in the buffer
        sem_wait(&buffer_sem); // Lock the buffer
        buffer[buffer_index] = item; // Put the item in the buffer
        buffer_index++; // Increment the buffer index
        printf("Producer produced %d\n", item);
        sem_post(&buffer_sem); // Unlock the buffer
        sem_post(&full_sem); // Signal that a full slot is available
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, item;
    for (i = 0; i < 20; i++) {
        sem_wait(&full_sem); // Wait for a full slot in the buffer
        sem_wait(&buffer_sem); // Lock the buffer
        item = buffer[buffer_index - 1]; // Take the item from the buffer
        buffer_index--; // Decrement the buffer index
        printf("Consumer consumed %d\n", item);
        sem_post(&buffer_sem); // Unlock the buffer
        sem_post(&empty_sem); // Signal that an empty slot is available
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    sem_init(&empty_sem, 0, BUFFER_SIZE);
    sem_init(&full_sem, 0, 0);
    sem_init(&buffer_sem, 0, 1);
    buffer_index = 0;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    sem_destroy(&empty_sem);
    sem_destroy(&full_sem);
    sem_destroy(&buffer_sem);
    return 0;
}
