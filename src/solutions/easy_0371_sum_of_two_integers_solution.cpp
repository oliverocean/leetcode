/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Sum Of Two Integers
 * @index: 371
 * @difficulty: easy
 * @topic: bit manipulation
 * @reqs: https://leetcode.com/problems/sum-of-two-integers/
 * @brief:
 *     Calculate the sum of two integers a and b, but you are not allowed
 *     to use the operator '+' or '-'
 * @example:
 *     Example 1:
 *         Input: a = 1, b = 2
 *         Output: 3
 *     Example 2:
 *         Input: a = -2, b = 3
 *         Output: 1
 */

#include <iostream>
#include <bitset>

/* ---[ function prototypes ]--- */
int getSum(int, int);
int getSumDebug(int, int);

/* ---[ function test driver ]--- */
int main()
{
    int a = 21;
    int b = -1;

    std::cout << "\n---input ---\n";
    std::cout << "[ " << std::bitset<8>(a) << " ] • " << a << " • (a) \n";
    std::cout << "[ " << std::bitset<8>(b) << " ] • " << b << " • (b) \n";

    //std::cout << "\n--- debug ---\n";
    int c = getSum(a, b);

    std::cout << "\n--- output ---\n";
    std::cout << "[ " << std::bitset<8>(c) << " ] • " << c << " • (c) \n";

    return 0;
}

/* ---[ final approach ]--- */
/* runtime: 0ms @ 100%, memory: 7.4mb @ 100% */
int getSum(int a, int b)
{
    unsigned int remainderBits; // using unsigned avoids negative number issues

    while (b != 0) {
        remainderBits = a & b;
        a = a ^ b;
        b = remainderBits << 1;
    }
    return a;
}

/* ---[ final approach with debug notes ]--- */
int getSumDebug(int a, int b)
{
    unsigned int remainderBits;

    while (b != 0) {

        std::cout << "[ " << std::bitset<8>(a) << " ] • " << a << " • (a) \n";
        std::cout << "[ " << std::bitset<8>(b) << " ] • " << b << " • (b) \n";
        remainderBits =  a & b;

        std::cout << "[ " << std::bitset<8>(a ^ b) << " ] • " << (a ^ b) << " • sum (XOR) w/out remainder bits\n";
        a = a ^ b;

        std::cout << "[ " << std::bitset<8>(remainderBits) << " ] • " << remainderBits << " • remainder bits\n";
        std::cout << "[ " << std::bitset<8>(remainderBits << 1) << " ] • " << (remainderBits << 1) << " • shift remainder bits left\n";
        b = remainderBits << 1;

        std::cout << "-------\n";
    }
    return a;
}

// EOF
