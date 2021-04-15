/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Valid Parentheses
 * @index: 020
 * @difficulty: easy
 * @topic: strings, stacks
 * @reqs: https://leetcode.com/problems/parentheses/
 * @brief:
 *     Given a string containing just the characters '(', ')', '{', '}',
 *     '[', and ']', determine if the input string is valid.
 *     An input string is valid if:
 *         > Open brackets must be closed by the same type of brackets
 *         > Open brackets must be closed in the correct order
 * @examples:
 *     Example 1: "()" => true
 *     Example 2: "()[]{}" => true
 *     Example 3: "(]" => false
 *     Example 4: "([)]" => false
 *     Example 5: "{()}" => true
 */

#include <iostream>


//----------------------------------------------------------------------------//
//---[ option a ]---//
bool isValid(std::string s)
{
    //TODO
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
int main()
{
    std::string setA = "()";
    std::string setB = "()[]{}";
    std::string setC = "(]";
    std::string setD = "}";
    std::string setE = "([)]";
    std::string setF = "{[]}";
    std::string setG = " ";
    std::string setH = "asdf";
    std::string setI;
    std::string setJ = "[";

    std::cout << "\nSet A: " << setA << "\n" << isValid(setA) << "\n1? (true)\n-------\n";
    std::cout << "\nSet B: " << setB << "\n" << isValid(setB) << "\n1? (true)\n-------\n";
    std::cout << "\nSet C: " << setC << "\n" << isValid(setC) << "\n0? (false)\n-------\n";
    std::cout << "\nSet D: " << setD << "\n" << isValid(setD) << "\n0? (false)\n-------\n";
    std::cout << "\nSet E: " << setE << "\n" << isValid(setE) << "\n0? (false)\n-------\n";
    std::cout << "\nSet F: " << setF << "\n" << isValid(setF) << "\n1? (true)\n-------\n";
    std::cout << "\nSet G: " << setG << "\n" << isValid(setG) << "\n1? (true)\n-------\n";
    std::cout << "\nSet H: " << setH << "\n" << isValid(setH) << "\n1? (true)\n-------\n";
    std::cout << "\nSet I: " << setI << "\n" << isValid(setI) << "\n1? (true)\n-------\n";
    std::cout << "\nSet J: " << setJ << "\n" << isValid(setJ) << "\n0? (false)\n-------\n";

    return 0;
}
//----------------------------------------------------------------------------//
//---[ eof ]---//
