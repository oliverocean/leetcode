/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Product of Array Except Self
 * @index: 238
 * @difficulty: medium
 * @topic: arrays
 * @reqs: https://leetcode.com/problems/product-of-array-except-self/
 * @brief:
 *      Given an array nums of n integers where n > 1,  return an array
 *      output such that output[i] is equal to the product of all the
 *      elements of nums except nums[i].
 * @example:
 *      Input:  [ 1, 2, 3, 4 ]
 *      Output: [ 24, 12, 8, 6 ]
 * @notes:
 *      > Constraint: It's guaranteed that the product of the elements
 *        of any prefix or suffix of the array (including the whole array)
 *        fits in a 32 bit integer.
 *      > Solve without division and in O(n)
 */

#include <iostream>
#include <vector>

/* ---[ function prototypes ]--- */
std::vector<int> productExceptSelf(std::vector<int>& nums);
std::vector<int> productExceptSelfDebug(std::vector<int>& nums);
std::vector<int> productExceptSelfAltOne(std::vector<int>& nums);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int>input {1, 2, 3, 4, 5, 6, 7};

    std::cout << "\n---[ input ]---\n";
    std::cout << "[ ";
    for (const auto& i: input) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    std::cout << "\n---[ debug ]---\n";
    std::vector<int> output = productExceptSelf(input);

    std::cout << "\n---[ output ]---\n";
    std::cout << "[ ";
    for (const auto& i: output) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    return 0;
}

/* ---[ two vector approach ]--- */
/* runtime: 36ms @ 97%, memory: 12mb @ 100% */
/* This approach uses separate vectors for lh and rh cumulative products then aggregates
 * both at the end. I think it's a little more readable than a single vector approach. */
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    // Each item equals the product of all items to the left of that element.
    // Initialize first item to 1 (at first pivot there are no items to left), work forward.
    std::vector<int> lh(nums.size());
    lh[0] = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        lh[i] = lh[i - 1] * nums[i - 1];
    }

    // Each item equals the product of all items to the right of that element.
    // Initialize last item to 1 (at last pivot there are no items to the right), work backward.
    std::vector<int> rh(nums.size());
    rh[nums.size() - 1] = 1;
    for (int j = static_cast<int>(nums.size() - 2); j >= 0; --j)
    {
        rh[j] = rh[j + 1] * nums[j + 1];
    }

    // The product of each lh and rh item results in total product sans pivot value.
    std::vector<int> result(nums.size());
    for (int k = 0; k < nums.size(); ++k)
    {
        result[k] = lh[k] * rh[k];
    }

    return result;
}

/* ---[ two vector approach with debug messages ]--- */
std::vector<int> productExceptSelfDebug(std::vector<int>& nums)
{
    std::vector<int> result(nums.size());

    std::vector<int> lh(nums.size());
    lh[0] = 1;

    std::vector<int> rh(nums.size());
    rh[nums.size() - 1] = 1; // set value of last element

    std::cout << "[ start ]\n";
    std::cout << "nums [ "; for (const auto& x: nums) { std::cout << x << ", "; } std::cout << "]\n";
    std::cout << "> lh [ "; for (const auto& y: lh) { std::cout << y << ", "; } std::cout << "]\n";
    std::cout << "> rh [ "; for (const auto& z: rh) { std::cout << z << ", "; } std::cout << "]\n---\n";

    for (int i = 1; i < nums.size(); ++i)
    {
        lh[i] = lh[i - 1] * nums[i - 1];
        std::cout << "> lh [ "; for (const auto& y: lh) { std::cout << y << ", "; } std::cout << "]\n";
    }

    std::cout << "---\n";

    for (int j = static_cast<int>(nums.size() - 2); j >= 0; --j)
    {
        rh[j] = rh[j + 1] * nums[j + 1];
        std::cout << "> rh [ "; for (const auto& z: rh) { std::cout << z << ", "; } std::cout << "]\n";
    }

    for (int k = 0; k < nums.size(); ++k)
    {
        result[k] = lh[k] * rh[k];
    }

    return result;
}

/* ---[ single vector approach ]--- */
/* runtime: 36ms @ 97%, memory: 12mb @ 100% */
/* Uses a single 'result' vector, first populating with lh products then calculating
 * rh product and evaluating against lh products along the way. Yes, less code and a
 * little more space efficient but perhaps not as easy to understand how it works? */
std::vector<int> productExceptSelfAltOne(std::vector<int>& nums)
{
    std::vector<int> result(nums.size());
    result[0] = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int rh = 1;
    for (int j = static_cast<int>(nums.size() - 1); j >= 0; --j)
    {
        result[j] = result[j] * rh;
        rh *= nums[j];
    }

    return result;
}

// EOF
