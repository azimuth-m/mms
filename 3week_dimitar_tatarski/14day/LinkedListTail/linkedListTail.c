#include "linkedListTail.h"

void
printList(struct ll *lli)
{
        struct node *head = lli->head;
        while(head) {
                printf("%d ", head->d.val);
                head = head->next;
        }
        printf("\n");
}

void
pushListEnd(struct data new_data, struct ll *lli)
{
        struct node **head = &(lli->head);
        if (!(*head)) {
                *head = malloc(sizeof(struct node));
                if(!*head)
                        exit(-1);
                (*head)->next = NULL;
                (*head)->d = new_data;
        }

        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        if (!new_node)
                exit(-1);
        new_node->next = NULL;
        new_node->d = new_data;

        struct node *cur_node = *head;
        while(cur_node->next)
                cur_node = cur_node->next;

        cur_node->next = new_node;
}
void
popListEnd(struct ll *lli, struct data *result)
{
        struct node **head = &(lli->head);
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
pushListHead(struct ll *lli, struct data new_data)
{
        struct node **head = &(lli->head);
        struct node *new_node = malloc(sizeof(struct node));
        if (!new_node)
                exit(-1);
        new_node->d = new_data;
        new_node->next = *head;
        *head = new_node;

        return 1;
}

void
popListHead(struct ll *lli, struct data *result)
{
        struct node **head = &(lli->head);
        if (!(*head))
                exit(-1);
        struct node *origin = *head;
        *head = (*head)->next;
        // Pri result NULL, ne zapazvame reziltata
        if (result)
                *result = origin->d;
        free(origin);
}

struct ll *
init_linked_list()
{
        struct ll *lli = malloc(sizeof(struct ll));
        if (!lli) {
                perror("Could not malloc\n");
                exit(-1);
        }
        lli->head = NULL;
        lli->tail = NULL;
        return lli;
}

void
delete_linked_list(struct ll *lli)
{
        // check if list is empty
        while (!(lli->head))
                popListHead(lli, NULL);
        free(lli);
}
