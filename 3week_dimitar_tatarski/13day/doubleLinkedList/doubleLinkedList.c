#include <stdio.h>
#include <stdlib.h>

struct data {
        int val;
};

struct node {
        struct data d;
        struct node *next;
        struct node *prev;
};

void
printList(struct node *head)
{
        while(head) {
                printf("%d ", head->d.val);
                head = head->next;
        }
        printf("\n");
}

struct node *
pushListEnd(struct data new_data, struct node **head)
{
        if (!(*head)) {
                *head = malloc(sizeof(struct node));
                if(!*head)
                        return *head;
                (*head)->next = NULL;
                (*head)->d = new_data;
                return *head;
        }

        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        if (!new_node)
                return new_node;
        new_node->next = NULL;
        new_node->d = new_data;

        struct node *cur_node = *head;
        while(cur_node->next)
                cur_node = cur_node->next;

        cur_node->next = new_node;
        return new_node;
}

void
popListEnd(struct node **head, struct data *result)
{
        if (!(*head)) {
                perror("Cannot pop from empty list");
                exit(-1);
        }
        if (!(*head)->next) {
                *result = (*head)->d;
                free(*head);
                *head = NULL;
        }

        struct node *origin = *head;
        while (origin->next->next)
                origin = origin->next;

        *result = origin->next->d;
        free(origin->next);
        origin->next = NULL;
}

int
pushListHead(struct node **head, struct data *new_data)
{
        struct node *new_node = malloc(sizeof(struct node));
        if (!new_node)
                exit(-1);
        new_node->d = *new_data;
        new_node->next = *head;
        *head = new_node;

        return 1;
}

void
popListHead(struct node **head, struct data *result)
{
        if (!(*head))
                exit(-1);
        struct node *origin = *head;
        *head = (*head)->next;
        *result = origin->d;
        free(origin);
}

int
main()
{
        struct data d1;

        struct node *head2 = NULL;

        printf("[%p]\n", pushListEnd((struct data){40}, &head2));
        printf("[%p]\n", pushListEnd((struct data){30}, &head2));
        printf("[%p]\n", pushListEnd((struct data){20}, &head2));

        printList(head2);

        popListEnd(&head2, &d1);
        printf("[%d]\n", d1.val);
        printList(head2);
        popListHead(&head2, &d1);
        printf("[%d]\n", d1.val);
        printList(head2);

        return 0;
}
