#include <stdio.h>
#include <stdint.h>

void
myMap(int arr[], int n, int (*fp)(int))
{
        for (size_t i = 0; i < n; i++) {
                arr[i] = fp(arr[i]);
        }
}

int
square(int a)
{
        return a * a;
}

int
addElement(int a)
{
        int temp;
        scanf("%d", &temp);
        return temp;
}

int
printArr(int a)
{
        printf(" %d ", a);
        return a;
}

int
main()
{
        int arr[100];
        myMap(arr, 5, addElement);
        myMap(arr, 5, printArr);
        myMap(arr, 5, square);
        myMap(arr, 5, printArr);
        return 0;
}
