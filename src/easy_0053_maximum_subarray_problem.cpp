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


//----------------------------------------------------------------------------//
//---[ option a ]---//
int maxSubArray(std::vector<int>& nums)
{
    //TODO
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
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
//----------------------------------------------------------------------------//
//---[ eof ]---//
