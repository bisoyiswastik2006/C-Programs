#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int main()
{
    int n, item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;
    }

    printf("Stack Elements:\n");

    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}