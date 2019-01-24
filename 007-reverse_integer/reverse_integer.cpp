#include <iostream>
#include <stdlib.h>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
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
};

int main()
{
    Solution solution;
    int num = 0;
    std::cout << "Input a number: ";
    std::cin >> num;

    std::cout << solution.reverse(num) << std::endl;

    return 0;
}