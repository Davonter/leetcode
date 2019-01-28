#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int reverse(int x)
{
    int y = 0;
    while(x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }

    return y;
}

static bool isPalindrome(int x)
{
    if(0 == x)
    {
        return true;
    }

    if(0 > x)
    {
        return false;
    }

    return x == reverse(x);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out number\n");
        exit(-1);
    }

    printf("%s\n", isPalindrome(atoi(argv[1])) ? "true" : "false");

    return 0;
}