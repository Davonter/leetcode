#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int reverse(int x)
{
    int y = 0;

    while(x != 0)
    {
        int n = x % 10;

        if(y > INT_MAX / 10 || y < INT_MIN / 10)
        {
            return 0;
        }

        y = y * 10 + n;
        x /= 10;
    }

    return y;
}

int main()
{
    int num = 0;

    printf("input a number: ");
    scanf("%d", &num);

    printf("The reversed number is : %d\n", reverse(num));

    return 0;
}