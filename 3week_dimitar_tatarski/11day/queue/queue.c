#include <stdio.h>
#include <stdlib.h>

typedef struct A {
        int data;
} A;

typedef struct Queue {
        A *arr;
        size_t capacity;
        size_t cur_elem_count;
} Queue;

Queue
init_queue(size_t capacity)
{
        Queue res;

        res.capacity = capacity;
        res.cur_elem_count = 0;
        res.arr = malloc(capacity * sizeof(A));
        return res;
}

int
enqueue(Queue *q, A new_elem)
{
        if(q->cur_elem_count == q->capacity)
                return -1;
        q->arr[q->cur_elem_count++] = new_elem;
        return 0;
}

int
dequeue(Queue *q, A *res)
{
       if (q->cur_elem_count == 0)
               return -1;
       if(res)
               *res = q->arr[0];
       q->cur_elem_count -= 1;
       for (size_t i = 0; i < q->cur_elem_count; i++) {
               q->arr[i] = q->arr[i+1];
       }
       return 0;
}

void
print_elems(Queue q)
{
        for (size_t i = 0; i < q.capacity; i++) {
                if (i < q.cur_elem_count) {
                        printf("%2d ", q.arr[i].data);
                } else {
                        printf("__ ");
                }
        }
        printf("\n");
}

void
deinit(Queue q)
{
        free(q.arr);
}

int
main()
{
        Queue q1 = init_queue(10);
        A removed_data;
        enqueue(&q1, (A){.data = 1});
        print_elems(q1);
        enqueue(&q1, (A){.data = 2});
        print_elems(q1);
        enqueue(&q1, (A){.data = 3});
        print_elems(q1);
        dequeue(&q1, &removed_data);
        printf("Removed: %d\n", removed_data.data);
        print_elems(q1);
        dequeue(&q1, NULL);
        printf("Removed \n");
        print_elems(q1);
        enqueue(&q1, (A){.data = 4});
        print_elems(q1);
        enqueue(&q1, (A){.data = 5});
        print_elems(q1);
        enqueue(&q1, (A){.data = 6});
        print_elems(q1);
        deinit(q1);
        return 0;
}
