#include "linkedList.h"

#ifndef QUEUE_H
#define QUEUE_H 1

typedef LL Queue;

Queue *init_queue();
void enqueue(Data, Queue *);
void dequeue(Data *, Queue *);
void print_queue(Queue *);
void deinit_queue(Queue *);

#endif
