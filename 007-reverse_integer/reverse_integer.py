#!/usr/bin/env python3

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = -int(str(abs(x))[::-1])
        else:
            x = int(str(abs(x))[::-1])
        
        if x > 2**31 or x < -2**31:
            return 0
        return x

solution = Solution()

print("Output: ", solution.reverse(123))