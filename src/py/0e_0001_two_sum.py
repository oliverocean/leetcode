#!/usr/bin/env python

# --[ easy_0001_two_sum.py ]------------------------------------------------- #
# https://leetcode.com/problems/two-sum/

'''
Given an array of integers 'nums' and an integer 'target', return indices of
the two numbers such that they add up to 'target'.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

Example 1:
    Input: nums = [2, 7, 11, 15], target = 9
    Output: [0,1]
    Output: Because nums[0] + nums[1] == 9 (2 + 7), return [0,1]

Example 2:
    Input: nums = [3, 2, 4], target = 6
    Output: [1,2]

Example 3:
    Input: nums = [3, 3], target = 6
    Output: [0,1]
'''


class Solution:

    # --[ top ]-------------------------------------------------------------- #
    # hash map, single pass
    def twoSum(self, nums, target):
        bucket = {}

        for index, value in enumerate(nums):

            if value in bucket:
                return [bucket[value], index]

            bucket[target - value] = index

        return []


# --[ driver ]--------------------------------------------------------------- #
driver = Solution()

# case a
nums_a = [2, 7, 11, 15]
target_a = 9
expect_a = [0, 1]
result_a = driver.twoSum(nums_a, target_a)

# case b
nums_b = [3, 2, 4]
target_b = 6
expect_b = [1, 2]
result_b = driver.twoSum(nums_b, target_b)

# case c
nums_c = [3, 3]
target_c = 6
expect_c = [0, 1]
result_c = driver.twoSum(nums_c, target_c)

# results
# watch -xtc python ./foo.py
print("--[ results ]--")
print(f' > a: {result_a} >> expect: {expect_a}')
print(f' > b: {result_b} >> expect: {expect_b}')
print(f' > c: {result_c} >> expect: {expect_c}')

# --[ eof ]-----------------------------------------------------------------> #
