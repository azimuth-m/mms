#include "linkedListTail.h"

int
main()
{
        struct data d1;
        struct ll *lli = init_linked_list();

        ushListHead(lli,(struct data){0});
        pushListHead(lli,(struct data){5});
        pushListHead(lli,(struct data){6});
        pushListHead(lli,(struct data){7});
        pushListHead(lli,(struct data){8});

        printList(lli);
        popListEnd(lli, &d1);
        printf("[%d]\n", d1.val);
        printList(lli);
        popListHead(lli, &d1);
        printf("[%d]\n", d1.val);
        printList(lli);

        return 0;
}
