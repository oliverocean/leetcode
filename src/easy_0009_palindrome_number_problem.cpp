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


//----------------------------------------------------------------------------//
//---[ option a ]---//
bool isPalindrome(int x)
{
    //TODO
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
int main()
{
    std::cout << "\n --- input --- \n";
    std::cout << "> 12321";
    std::cout << "\n --- result --- \n";
    std::cout << "> " << isPalindrome(12321) << "\n";

    return 0;
}
//----------------------------------------------------------------------------//
//---[ eof ]---//
