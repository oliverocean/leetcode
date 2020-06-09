/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Reverse Integer
 * @index: 007
 * @difficulty: easy
 * @topic: math
 * @reqs: https://leetcode.com/problems/reverse-integer/
 * @brief:
 *     Given a 32-bit signed integer, reverse digits of an integer.
 * @example:
 *     Example 1:
 *         Input: 123
 *         Output: 321
 *     Example 2:
 *         Input: -123
 *         Output: -321
 *     Example 3:
 *         Input: 120
 *         Output: 21
 * @note:
 *     Assume we are dealing with an environment which could only store integers within
 *     the 32-bit signed integer range [-2^31, 2^31 - 1]. For the purpose of this problem,
 *     assume that your function returns 0 when the reverse integer overflows.
 */

#include <iostream>
#include <climits>

/* ---[ function prototypes ]--- */
int reverse(int);
int reverseAltOne(int);

/* ---[ function test driver ]--- */
int main()
{
    std::cout << "\n --- input --- \n";
    std::cout << "> 1234";
    std::cout << "\n --- result --- \n";
    std::cout << "> " << reverse(1234) << "\n";
    return 0;
}

/* ---[ final approach ]--- */
int reverse(int x)
{
    int reversed{0};

    while (x != 0)
    {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }
    return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : reversed;
}

/* ---[ initial approach ]--- */
int reverseAltOne(int x)
{
    int reversed{0};

    while (x != 0)
    {
        int popped = x % 10;

        if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && popped > 7)) return 0;
        if (reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && popped < -8)) return 0;

        reversed = reversed * 10 + popped;
        x /= 10;
    }
    return reversed;
}

// EOF