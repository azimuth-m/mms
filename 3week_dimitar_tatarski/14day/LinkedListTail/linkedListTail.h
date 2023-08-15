#include <stdio.h>
#include <stdlib.h>

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H 1

struct data {
        int val;
};

struct node {
        struct data d;
        struct node *next;
        struct node *prev;
};

struct ll {
        struct node *head;
        struct node *tail;
};

void printList(struct ll *);
void pushListEnd(struct data, struct ll *);
void popListEnd(struct ll *, struct data *);
int pushListHead(struct ll *, struct data);
void popListHead(struct ll *, struct data *);
struct ll *init_linked_list();
void delete_linked_list(struct ll *);

#endif

