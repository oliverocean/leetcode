/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Best Time to Buy and Sell Stock
 * @index: 121
 * @difficulty: easy
 * @topic: arrays, vectors, divide and conquer, dynamic programming
 * @reqs: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @brief:
 *     Say you have an array for which the ith element is the price of a given stock on day i.
 *     If you were only permitted to complete at most one transaction (i.e., buy one and sell
 *     one share of the stock), design an algorithm to find the maximum profit.
 *     Note: you cannot sell a stock before you buy one.
 * @example:
 *     Input: [ 7, 1, 5, 3, 6, 4 ]
 *     Output: [ 5 ]
 *     Explanation:
 *         Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit is 6 - 1 = 5
 *         Not 7 - 1 = 6, as selling price needs to be larger than buying price.
 */

#include <iostream>
#include <vector>
#include <climits>

/* ---[ function prototypes ]--- */
int maxProfit(std::vector<int>&);
int maxProfitDebug(std::vector<int>&);
int maxProfitAltOne(std::vector<int>&);
int maxProfitAltTwo(std::vector<int>&);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int>input {7, 1, 5, 3, 6, 4};

    std::cout << "\n---[ input ]---\n";
    std::cout << "daily price: [ ";
    for (const auto& i: input) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    std::cout << "\n---[ debug ]---\n";
    int output = maxProfit(input);

    std::cout << "\n---[ output ]---\n";
    std::cout << "result: [ $" << output << " ]\n";

    return 0;
}

/* ---[ revised approach, simplified naming, more readable ]--- */
/* runtime: 4ms @ 98%, memory: 8.8mb @ 100% */
int maxProfit(std::vector<int>& prices)
{
    int buy = INT_MAX;
    int profit = 0;

    for (int price : prices)
    {
        buy = std::min(buy, price);
        profit = std::max(profit, price - buy);
    }

    return profit;
}

/* ---[ revised approach with debug output ]--- */
int maxProfitDebug(std::vector<int>& prices)
{
    if (prices.empty()) { return 0; }

    std::cout << "\nday 1, price is $" << prices[0] << " (set min)\n";
    int buy = prices[0];
    int profit = 0;

    for (int p = 1; p < prices.size(); ++p)
    {
        std::cout << "\nday " << p + 1 << ", price is $" << prices[p] << "\n";
        if (prices[p] < buy) {
            std::cout << "min found $" << prices[p] << "\n";
            buy = prices[p];
        }
        else if (prices[p] - buy > profit)
        {
            std::cout << "max profit found $"<< prices[p] - buy << "\n";
            profit = prices[p] - buy;
        }
        else
        {
            std::cout << "minBuy < n (between) < maxProfit\n";
        }
    }
    return profit;
}

/* ---[ Kanade's Algorithm approach ]--- */
/* interesting solution found online, needs further analysis */
int maxProfitAltOne(std::vector<int>& prices)
{
    int price = 0;
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        price += prices[i] - prices[i - 1];
        price = std::max(price, 0);
        profit = std::max(profit, price);
    }
    return profit;
}

/* ---[ brute force approach ]--- */
/* runtime: 868ms @ 6.76% (very poor!), memory: 9mb @ 100% (excellent) */
int maxProfitAltTwo(std::vector<int>& prices)
 {
    int result = 0;
    int largestSoFar;

    for (int n = 0; n < prices.size(); ++n)
    {
        std::cout << "\nday " << n << ", buy @ $" << prices[n] << "\n";
        for (int m = static_cast<int>(prices.size() - 1); m > n; --m)
        {
            largestSoFar = prices[m] - prices[n];
            std::cout << "> day " << m << ", sell @ $" << prices[m] << ", profit [ $" << largestSoFar << " ]\n";
            if (largestSoFar > result)
            {
                result = largestSoFar;
            }
        }
    }
    return result;
}

// EOF