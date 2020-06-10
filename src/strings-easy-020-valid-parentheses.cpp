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
#include <stack>
#include <unordered_map>

/* ---[ function prototypes ]--- */
bool isValid(std::string);
bool isValidDebug(std::string);
bool isValidAltOne(std::string);

/* ---[ function test driver ]--- */
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

/* ---[ simple approach using stack ]--- */
/* runtime: 0ms @ 100%, memory: 8.6mb @ 71% */
bool isValid(std::string s)
{
    if (s.empty()) { return true; }

    std::stack<char> aStack;

    for (int i = 0; i < s.length(); ++i )
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            aStack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (aStack.empty())
            {
                return false;
            }
            else if (aStack.top() == '(' && s[i] == ')')
            {
                aStack.pop();
            }
            else if (aStack.top() == '{' && s[i] == '}')
            {
                aStack.pop();
            }
            else if (aStack.top() == '[' && s[i] == ']')
            {
                aStack.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    return aStack.empty();
}

/* ---[ simple approach using stack with debug output ]--- */
bool isValidDebug(std::string s)
{
    if (s.empty())
    {
        std::cout << "> input string is empty but no errors.\n";
        return true;
    }

    std::stack<char> aStack;

    for (int i = 0; i < s.length(); ++i )
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            std::cout << "push: " << s[i] << "\n";
            aStack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (aStack.empty())
            {
                std::cout << "? eval: " << s[i] << "\n";
                std::cout << "rh value encountered, nothing in stack to match.\n";
                return false;
            }
            else if (aStack.top() == '(' && s[i] == ')')
            {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            }
            else if (aStack.top() == '{' && s[i] == '}')
            {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            }
            else if (aStack.top() == '[' && s[i] == ']')
            {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            }
            else
            {
                std::cout << "> mismatch found (stack not empty).\n";
                return false;
            }
        }
        else
        {
            std::cout << "> no errors but input string has no values to assess.\n";
            return true;
        }
    }
    std::cout << "> stack empty, no errors along the way.\n";
    return aStack.empty();
}

/* ---[ map approach ]--- */
/* more succinct but perhaps less easy to understand? Problematic
 * with a few of the test cases as well... needs more thought */
bool isValidAltOne(std::string s)
{
    if (s.empty()) { return true; }

    std::stack<char> aStack;
    std::unordered_map<char, char> aMap { {'(',')'}, {'{','}'}, {'[',']'} };

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            aStack.push(s[i]);
        }
        else if (aStack.empty() || aMap[aStack.top()] != s[i])
        {
            return false;
        }
        else
        {
            aStack.pop();
        }
    }
    return aStack.empty();
}

// EOF