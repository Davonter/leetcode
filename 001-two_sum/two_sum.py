#!/usr/bin/env python3

class Solution:
    def twoSum(self, nums, target):
        """
        type nums: List[int]
        type target: int
        r type: List[int] 
        """
        dic = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in dic:
                return [dic[another_num], index]
            dic[num] = index
        return None
        
nums = [1, 3, 5, 7]
target = 6

result = Solution()
print(result.twoSum(nums, 6))