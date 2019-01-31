#include <stdio.h>
#include <stdlib.h>

static int roman_to_int(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

static int romanToInt(char *s)
{
    int result = roman_to_int(s[0]);
    int i = 0;

    for(i = 1; s[i] != '\0'; i++)
    {
        int prev = roman_to_int(s[i-1]);
        int curr = roman_to_int(s[i]);

        if(prev < curr)
        {
            result = result - prev + (curr - prev);
        }
        else
        {
            result += curr;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s romanstring...", argv[0]);
        exit(-1);
    }

    printf("%d\n", romanToInt(argv[1]));

    return 0;
}