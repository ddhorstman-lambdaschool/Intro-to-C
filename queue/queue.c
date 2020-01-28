#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *q = malloc(sizeof(Queue));
    q->storage = malloc(capacity);
    q->capacity = capacity;
    q->length = 0;
    return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{

    // if (q->length >= sizeof(*(q->storage)) / sizeof(int))
    //     q->storage = realloc(q->storage, q->length + 1);
    if(q->length >= q->capacity) q->storage = realloc(q->storage, ++q->capacity);
    q->storage[q->length] = item;
    q->length++;
    //if(++q->length>q->capacity)q->storage=realloc(q->storage,++q->capacity);
    //*(q->storage+q->length)=item;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->length == 0)
        return -1;
    int item = q->storage[0];
    unsigned int i;
    for(i = 0; i < q->length; i++)q->storage[i]=q->storage[i+1];
    q->storage[i]=0;
    q->length--;
    return item;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->storage != NULL)
        free(q->storage);
    if (q != NULL)
        free(q);
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    printf("%d\n", q->storage[0]);
    enqueue(q, 2);
    printf("%d\n", q->storage[1]);
    enqueue(q, 4);
    printf("%d\n", q->storage[2]);
    enqueue(q, 4);
    printf("%d\n", q->storage[3]);
    enqueue(q, 5);
    printf("%d\n", q->storage[4]);
    enqueue(q, 6);
    printf("%d\n", q->storage[5]);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif