/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Longest Common Prefix
 * @index: 014
 * @difficulty: easy
 * @topic: strings
 * @reqs: https://leetcode.com/problems/longest-common-prefix/
 * @brief:
 *     Write a function to find the longest common prefix amongst an array of strings.
 *     If there is no common prefix, return an empty string "".
 * @example:
 *     Example 1:
 *         Input: ["flower", "flow", "flight"]
 *         Output: "fl"
 *     Example 2:
 *         Input: ["dog", "racecar", "car"]
 *         Output: ""
 *         Explain: no common prefix among input strings
 * @note: All given inputs are in lowercase letters a-z.
 */

#include <iostream>
#include <vector>


//----------------------------------------------------------------------------//
//---[ option a ]---//
std::string longestCommonPrefix(std::vector<std::string>& some_strings)
{
    //TODO
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
int main()
{
    std::vector<std::string> setA {"flower","flow","flight", "flex", "florist"};
    std::vector<std::string> setB {"dog","cat","bird", "giraffe", "fish"};
    std::vector<std::string> setC;

    std::cout << "\n--- result a ---\n";
    std::cout << "> " << longestCommonPrefix(setA);

    std::cout << "\n--- result b ---\n";
    std::cout << "> " << longestCommonPrefix(setB);

    return 0;
}

//----------------------------------------------------------------------------//
//---[ eof ]---//
