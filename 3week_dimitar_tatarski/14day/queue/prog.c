#include "linkedList.h"
#include "queue.h"

int main() {
    LL *ll = init_linked_list();
    push_back((Data){1}, ll);
    print_linked_list(ll);
    push_back((Data){2}, ll);
    print_linked_list(ll);
    push_back((Data){3}, ll);
    print_linked_list(ll);
    push_back((Data){4}, ll);
    print_linked_list(ll);
    Data d;
    pop_back(ll, &d);
    print_linked_list(ll);
    pop_front(ll, NULL);
    print_linked_list(ll);
    pop_front(ll, NULL);
    print_linked_list(ll);
    deinit_linked_list(ll);

printf("\nQueue:\n");

    Queue *q1;
    Data d1;
    q1 = init_queue();
    enqueue((Data){1}, q1);
    print_queue(q1);
    enqueue((Data){2}, q1);
    print_queue(q1);
    enqueue((Data){3}, q1);
    print_queue(q1);
    enqueue((Data){4}, q1);
    print_queue(q1);
    dequeue(&d1, q1);
    print_queue(q1);
    dequeue(&d1, q1);
    print_queue(q1);
    dequeue(NULL, q1);
    print_queue(q1);
    deinit_queue(q1);
    return 0;
}
