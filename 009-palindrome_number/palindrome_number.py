#!/usr/bin/env python3

import sys

class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        else:
            y = str(x)[::-1]
            return y == str(x)

sol = Solution()

x = sys.argv[1]

print(sol.isPalindrome(int(x)))