#include <stdio.h>

int main()
{
    int n;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial = %lld", fact);

    return 0;
}