#include <stdio.h>
#include <math.h>

int main()
{
    int num, temp, rem, digits = 0;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while(temp != 0)
    {
        digits++;
        temp /= 10;
    }

    temp = num;

    while(temp != 0)
    {
        rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }

    if(sum == num)
        printf("%d is an Armstrong Number.", num);
    else
        printf("%d is not an Armstrong Number.", num);

    return 0;
}