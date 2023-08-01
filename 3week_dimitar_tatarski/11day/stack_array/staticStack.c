#include <stdio.h>
#include <stdlib.h>


struct A {
        int data;
};

struct Stack {
        struct A *arr;
        size_t cap;
        size_t cur_ecnt;
};

struct Stack
initStackArray(size_t ecnt) {
        struct Stack res;

        res.cap = ecnt;
        res.cur_ecnt = 0;
        res.arr = (malloc(ecnt * sizeof(struct A)));
        return res;
}

void
destructStack(struct Stack s) {
        free(s.arr);
}

int
push(struct Stack *s, struct A el) {
        if (s->cur_ecnt == s->cap)
                return -1;
        s->arr[s->cur_ecnt] = el;
        (s->cur_ecnt)++;
        return 1;
}

int
pop(struct Stack *s, struct A *res) {
        if (!(s->cur_ecnt))
                return -1;
        if(res)
                *res = s->arr[s->cur_ecnt-1];
        s->cur_ecnt--;
        return 1;
}

void
printArr(struct Stack s) {
        for (size_t i = 0; i < s.cap; i++) {
                if (i < s.cur_ecnt)
                        printf("%2d ", s.arr[i].data);
                else
                        printf("__ ");
        }
        printf("\n");
}

int
main()
{
        struct Stack s1 = initStackArray(10);
                push(&s1, (struct A){ .data = 10});
                push(&s1, (struct A){ .data = 20});
                push(&s1, (struct A){ .data = 30});
                printArr(s1);

        struct Stack s2 = initStackArray(5);
                push(&s2, (struct A){ .data = 1 });
                push(&s2, (struct A){ .data = 2 });
                push(&s2, (struct A){ .data = 3 });
                printArr(s2);
    destructStack(s1);
    destructStack(s2);
        return 0;
}
