#include "queue.h"

Queue *
init_queue()
{
        return init_linked_list();
}

void
enqueue(Data new_elem, Queue *q)
{
        push_back(new_elem, q);
}

void
dequeue(Data *new_elem, Queue *q)
{
        pop_front(q, new_elem);
}

void
print_queue(Queue *q)
{
        print_linked_list(q);
}

void
deinit_queue(Queue *q)
{
        deinit_linked_list(q);
}
