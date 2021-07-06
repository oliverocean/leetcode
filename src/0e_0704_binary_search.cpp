/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Binary Search
 * @index: 704
 * @difficulty: easy
 * @topic: search, binary search
 * @reqs: https://leetcode.com/problems/binary-search/
 * @brief:
 *     Given a sorted (in ascending order) integer array 'nums' of 'n' elements
 *     and a 'target' value, write a function to search 'target' in 'nums'.
 *     If 'target' exists, return it's index, otherwise return -1.
 * @example:
 *     Example 1:
 *         Input: nums = [ -1, 0, 3, 5, 9, 12 ], target = 9
 *         Output: 4
 *         Explain: 9 exists in 'nums' and it's index = 4
 *     Example 2:
 *         Input: nums = [ -1, 0, 3, 5, 9, 12 ], target = 2
 *         Output: -1
 *         Explain: 2 does not exist in 'nums', so return -1
 * @notes:
 *     > Assume all elements in 'nums' are unique
 *     > 'n' will be in the range [ 1, 10000 ]
 *     > The value of each element in 'nums' will be in the range [ -9999, 9999 ]
 */

#include <iostream>
#include <vector>

/* ---[ function prototypes ]--- */
int search(std::vector<int>&, int);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int> items{1, 0, 3, 5, 6, 7, 8, 44, 66, 9, 12};
    int target{6};

    std::cout << "\n --- results --- \n";
    std::cout << search(items, target);

    return 0;
}

/* ---[ final approach ]--- */
int search(std::vector<int>& items, int target)
{
    if (items.empty()) { return -1; }

    int low{};
    int high{static_cast<int>(items.size() - 1)};
    int guess{};

    while (low <= high)
    {
        guess = low + (high - low) / 2;

        if (items[guess] == target)
        {
            return guess;
        }
        else if (items[guess] < target)
        {
            low = guess + 1;
        }
        else
        {
            high = guess - 1;
        }
    }
    return -1;
}

// EOF