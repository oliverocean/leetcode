/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Maximum Subarray
 * @index: 053
 * @difficulty: easy
 * @topic: arrays, vectors, divide and conquer, dynamic programming
 * @reqs: https://leetcode.com/problems/maximum-subarray/
 * @brief:
 *     Given an integer array 'nums', find the contiguous subarray (containing
 *     at least one number), which has the largest sum and return its sum.
 * @example:
 *     Input: [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ]
 *     Output: [ 6 ]
 *     Explanation: [ 4, -1, 2, 1 ] has the largest sum = 6
 */

#include <iostream>
#include <vector>
#include <climits>

/* ---[ function prototypes ]--- */
int maxSubArray(std::vector<int>& nums);
int maxSubArrayDebug(std::vector<int>& nums);
int maxSubArrayAlt(std::vector<int>& nums);

/* ---[ function test driver ]--- */
int main()
{
    std::cout << "\n---[ input ]---\n";

    std::cout << "> Original Vector:\n";
    std::vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // should be 6
    //std::vector<int> nums {1}; // should be 1
    //std::vector<int> nums {-2, 1}; // should be 1
    std::cout << " [ "; for (const auto& n : nums) { std::cout << n << ", "; } std::cout << "]";

    std::cout << "\n\n---[ debug ]---\n";
    int result = maxSubArray(nums);

    std::cout << "\n\n---[ output ]---\n";
    std::cout << "> result:\n [ " << result << " ]\n";
}

/* ---[ second, improved approach ]--- */
/* runtime: 4ms @ 97% + memory: 7mb @ 100% */
int maxSubArray(std::vector<int>& nums)
{
    int previousMax = INT_MIN;
    int recentStreak = 0;

    for (auto currentItem : nums)
    {
        recentStreak = std::max(currentItem, recentStreak + currentItem);
        previousMax = std::max(recentStreak, previousMax);
    }
    return previousMax;
}

/* ---[ improved approach with debug output ]--- */
int maxSubArrayDebug(std::vector<int>& nums)
{
    int previousMax = INT_MIN;
    int recentStreak = 0;

    for (auto currentItem : nums)
    {
        std::cout << "\n--->\n";
        std::cout << "• currentItem [ " << currentItem << " ]\n";
        std::cout << "• recentStreak [ " << recentStreak << " ]\n";
        std::cout << "• previousMax [ " << previousMax << " ]\n";
        std::cout << "-\n";
        std::cout << "> recentStreak = max(currentItem, currentItem + recentStreak)?\n";
        std::cout << "<< [ " << currentItem << " ] OR [ " << currentItem + recentStreak << " ] \n";
        recentStreak = std::max(currentItem, recentStreak + currentItem);
        std::cout << "recentStreak [ " << recentStreak << " ]\n";
        std::cout << "-\n";
        std::cout << "> previousMax = max(recentStreak, previousMax)?\n";
        std::cout << "<< [ " << recentStreak << " ] OR [ " << previousMax << " ]\n";
        previousMax = std::max(recentStreak, previousMax);
        std::cout << "previousMax [ " << previousMax << " ]\n";
    }
    return previousMax;
}

/* ---[ brute force, first attempt ]--- */
/* runtime 744ms @ 5% (poor) + memory 7mb @ 100% (excellent) */
int maxSubArrayAlt(std::vector<int>& nums)
{
    int result = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        int max = nums[i];
        int sum = nums[i];

        for (int n = i + 1; n < nums.size(); ++n)
        {
            sum += nums[n];
            if (sum > max)
            {
                max = sum;
            }
        }
        if (max > result)
        {
            result = max;
        }
    }
    return result;
}

// EOF