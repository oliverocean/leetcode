#!/usr/bin/env python

# --[ easy_0167_two_sum_ii.py ]---------------------------------------------- #
# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

'''
Given an array of integers numbers that is already sorted in non-decreasing
order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of
size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution.
You may not use the same element twice.

Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:
    Input: numbers = [2,3,4], target = 6
    Output: [1,3]

Example 3:
    Input: numbers = [-1,0], target = -1
    Output: [1,2]
'''
# NOTE: odd requirements; asking to return the pair of indices as usual,
#       but here they expect the array 'numbers' indexed from 1 instead of 0.


class Solution:

    # --[ top ]-------------------------------------------------------------- #
    def twoSum(self, numbers, target):
        # TODO

        return []


# --[ driver ]--------------------------------------------------------------- #
driver = Solution()

# case a
numbers_a = [2, 7, 11, 15]
target_a = 9
expect_a = [1, 2]
result_a = driver.twoSum(numbers_a, target_a)

# case b
numbers_b = [2, 3, 4]
target_b = 6
expect_b = [1, 3]
result_b = driver.twoSum(numbers_b, target_b)

# case c
numbers_c = [-1, 0]
target_c = -1
expect_c = [1, 2]
result_c = driver.twoSum(numbers_c, target_c)

# results
# watch -xtc python ./foo.py
print("--[ results ]--")
print(f' > a: {result_a} >> expect: {expect_a}')
print(f' > b: {result_b} >> expect: {expect_b}')
print(f' > c: {result_c} >> expect: {expect_c}')

# --[ eof ]-----------------------------------------------------------------> #
