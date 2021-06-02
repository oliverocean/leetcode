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
    # enumerate loop
    def twoSum(self, nums, target):
        bucket = {}

        for index, value in enumerate(nums):
            match = target - nums[index]

            if match in bucket:
                return [bucket[match], index]
            else:
                bucket[value] = index

        return []

    # --[ top ]-------------------------------------------------------------- #
    # with comments
    def twoSum_with_comments(self, nums, target):

        # stores key (index), value pairs found in 'nums' array
        bucket = {}

        # look through nums array
        for index, value in enumerate(nums):

            # the value of each nums index has a match which sums up to target
            match = target - nums[index]

            # if match has been seen previously, return the pair of indices:
            # 'old' index is a key in bucket, paired with the value of match
            # 'new' index is the nums index during this loop iteration
            if match in bucket:
                return [bucket[match], index]

            # if no match, store this key (index) and value in bucket
            else:
                bucket[value] = index

        # if none of the values in array meet reqs, return empty list
        return []

    # --[ alt ]-------------------------------------------------------------- #
    # interesting solution found here:
    # https://leetcode.com/problems/two-sum/discuss/737092
    def twoSumC(self, nums, target):

        # left starts at index 0
        for left_index in range(len(nums)):
            right_index = len(nums) - 1

            while left_index < right_index:
                a_sum = nums[left_index] + nums[right_index]

                if a_sum > target:
                    right_index -= 1
                elif a_sum < target:
                    left_index += 1
                else:
                    return [left_index, right_index]

    # --[ alt ]-------------------------------------------------------------- #
    def twoSumB(self, nums, target):

        for index in range(len(nums)):
            match = target - nums[index]

            if match in nums and nums.index(match) != index:
                return[index, nums.index(match)]

        return []

    # --[ brute force ]------------------------------------------------------ #
    def twoSumA(self, nums, target):
        for index, value in enumerate(nums):
            for index_match, value_match in enumerate(nums):
                if value + value_match == target and index != index_match:
                    return [index, index_match]


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
