#include <iostream>
#include <stdlib.h>
#include <cstdio>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int numSrc = x;
        int numDst = 0;
        if (x < 0)
        {
            return false;
        }

        while (numSrc)
        {
            numDst = numDst * 10 + numSrc % 10;
            numSrc /= 10;
        }

        return (numDst == x);
    }
};

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s number\n", argv[0]);
        exit(-1);
    }

    Solution solution;

    std::cout << std::boolalpha << solution.isPalindrome(atoi(argv[1])) << std::endl;

    return 0;
}