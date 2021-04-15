/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Two Sum
 * @index: 001
 * @difficulty: easy
 * @topic: arrays, vectors, maps
 * @reqs: https://leetcode.com/problems/two-sum/
 * @brief:
 *     Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *     You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * @example:
 *     Given nums = [2, 7, 11, 15], target = 9
 *     Because nums[0] + nums[1] = 2 + 7 = 9
 *     Return: [0, 1]
 */

#include <iostream>
#include <vector>


//----------------------------------------------------------------------------//
//---[ option a ]---//
std::vector<int> two_sum_a(std::vector<int>& nums, int target)
{
    //TODO

    return nums;
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
int main()
{
    int target{95};
    std::vector<int> nums {2, 7, 11, 15, 42, 56, 77, 88, 33};
    std::vector<int> results{};

    results = two_sum_a(nums, target);

    std::cout << "\n> input:   [ ";
    for (const auto& i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << " ]";

    std::cout << "\n> target:  [ " << target << " ]";
    std::cout << "\n> values:  [ " << nums[results[0]] << " + " << nums[results[1]] << " ]";
    std::cout << "\n> indexes: [ " << results[0] << " + " << results[1] << " ]\n";

    return 0;
}
//----------------------------------------------------------------------------//
//---[ eof ]---//
