/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Palindrome Number
 * @index: 009
 * @difficulty: easy
 * @topic: math
 * @reqs: https://leetcode.com/problems/palindrome-number/
 * @brief:
 *     Determine whether an integer is a palindrome. An integer is a palindrome
 *     when it reads the same backward as forward.
 * @example:
 *     Example 1:
 *         Input: 121
 *         Output: true
 *     Example 2:
 *         Input: -121
 *         Output: false
 *         Explain: right to left is 121- therefore not a palindrome
 *     Example 3:
 *         Input: 10
 *         Output: false
 *         Explain: right to left is 01, therefore not a palindrome
 */

#include <iostream>

/* ---[ function prototypes ]--- */
bool isPalindrome(int);
bool isPalindromeDebug(int);

/* ---[ function test driver ]--- */
int main()
{
    std::cout << "\n --- input --- \n";
    std::cout << "> 12321";
    std::cout << "\n --- result --- \n";
    std::cout << "> " << isPalindrome(12321) << "\n";

    return 0;
}

/* ---[ final approach ]--- */
bool isPalindrome(int x)
{
    if(x < 0 || (x % 10 == 0 && x != 0)) { return false; }

    int reversed{0};

    while (x > reversed)
    {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }

    return x == reversed || x == reversed/10;
}


/* ---[ final approach with notes ]--- */
bool isPalindromeDebug(int x)
{
    // per reqs: reject negative numbers and numbers that do not have symmetrical 0's
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int reversed{0};

    // exits loop when halfway through the reversal process (only half is needed for eval)
    while (x > reversed)
    {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }

    // if a palindrome with even # of digits, the left will be true
    // if a palindrome with odd # of digits, reversed/10 dumps middle number
    return x == reversed || x == reversed/10;
}

// EOF