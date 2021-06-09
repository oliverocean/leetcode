#!/usr/bin/env python

# --[ easy_0007_reverse_integer.py ]----------------------------------------- #
# https://leetcode.com/problems/reverse-integer/

'''
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer
range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers
(signed or unsigned).

Example 1:
    Input: x = 123
    Output: 321

Example 2:
    Input: x = -123
    Output: -321

Example 3:
    Input: x = 120
    Output: 21

Example 4:
    Input: x = 0
    Output: 0
'''


class Solution:

    # --[ top ]-------------------------------------------------------------- #
    def reverse(self, x):

        rev = int(str(abs(x))[::-1])

        return (rev if x > 0 else -rev) if rev.bit_length() < 32 else 0


# --[ driver ]--------------------------------------------------------------- #
driver = Solution()

# case a
x_a = 123
expect_a = 321
result_a = driver.reverse(x_a)

# case b
x_b = -123
expect_b = -321
result_b = driver.reverse(x_b)

# case c
x_c = 120
expect_c = 21
result_c = driver.reverse(x_c)

# results
# watch -xtc python ./foo.py
print(" --[ results ]--")
print(f' > a: {result_a} >> expect: {expect_a}')
print(f' > b: {result_b} >> expect: {expect_b}')
print(f' > c: {result_c} >> expect: {expect_c}')

# --[ eof ]-----------------------------------------------------------------> #
