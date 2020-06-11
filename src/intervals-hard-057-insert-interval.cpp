/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Insert Interval
 * @index: 057
 * @difficulty: hard
 * @topic: array, sort, intervals
 * @reqs: https://leetcode.com/problems/insert-interval/
 * @brief:
 *      Given a set of non-overlapping intervals, insert a new
 *      interval into the intervals (merge if necessary).
 * @ examples:
 *      Example 1:
 *          Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *          Output: [[1,5],[6,9]]
 *      Example 2:
 *          Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *          Output: [[1,2],[3,10],[12,16]]
 *          Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 * @note:
 *      You may assume that the intervals were initially sorted
 *      according to their start times.
 */

#include <iostream>
#include <vector>
#include <set>

/* ---[ function prototypes ]--- */
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>&, std::vector<int>&);

/* ---[ function test driver ]--- */
int main()
{
    std::cout << "\n---[ input ]---\n";

    std::cout << "> Original Intervals\n";
    //std::vector<std::vector<int>> intervals {{1, 3}, {6, 9}};
    //std::vector<std::vector<int>> intervals {{3, 4}, {5, 6}, {7, 8}, {9, 10}};
    //std::vector<std::vector<int>> intervals {{2, 3}, {4, 5}, {6, 7}, {8, 9}};
    std::vector<std::vector<int>> intervals {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    for (const auto& row : intervals)
    {
        std::cout << "[ ";
        for (const auto& col : row)
        {
            std::cout << col << ", ";
        }
        std::cout << "] ";
    }

    std::cout << "\n> New Interval ";
    std::vector<int> newInterval {5, 6};
    //std::vector<int> newInterval {5, 8};
    //std::vector<int> newInterval {10, 11};
    //std::vector<int> newInterval {5, 9};
    std::cout << "[ ";
    for (const auto& item : newInterval)
    {
        std::cout << item << ", ";
    }
    std::cout << "]\n";

    std::cout << "\n---[ debug ]---\n";
    std::vector<std::vector<int>> revisedIntervals = insert(intervals, newInterval);

    std::cout << "\n\n---[ output ]---\n";
    for (const auto& row : revisedIntervals)
    {
        std::cout << "[ ";
        for (const auto& col : row)
        {
            std::cout << col << ", ";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    return 0;
}

/* ---[ final approach ]--- */
/* runtime: 16ms @ 83%, memory: 12mb @ 100% */
/* realizing reqs ask to modify the existing vector...
 * this solution returns a new vector instead.  :|  */
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                     std::vector<int>& newInterval)
{
    std::vector<std::vector<int>>revisedIntervals;

    int i{0};
    int lh{0};
    int rh{1};

    while (i < intervals.size() && intervals[i][rh] < newInterval[lh])
    {
        revisedIntervals.push_back(intervals[i++]);
    }

    while (i < intervals.size() && intervals[i][lh] <= newInterval[rh])
    {
        newInterval[lh] = std::min(newInterval[lh], intervals[i][lh]);
        newInterval[rh] = std::max(newInterval[rh], intervals[i][rh]);
        ++i;
    }

    revisedIntervals.push_back(newInterval);

    while (i < intervals.size())
    {
        revisedIntervals.push_back(intervals[i++]);
    }

    return revisedIntervals;
}


/* ---[ final approach with debug output and notes ]--- */
std::vector<std::vector<int>> insertDebug(std::vector<std::vector<int>>& intervals,
                                            std::vector<int>& newInterval)
{
    std::vector<std::vector<int>>revisedIntervals;

    int i = 0;
    int lh = 0;
    int rh = 1;

    std::cout << "\n---[ add head interval(s) ]---\n";
    std::cout << "Start [ " << intervals[i][lh] << ", "
                            << intervals[i][rh] << " ] (index " << i << ")\n";
    std::cout << "Seek [ " << newInterval[lh] << ", " << newInterval[rh] << " ]\n";
    while (i < intervals.size() && intervals[i][rh] < newInterval[lh])
    {
        revisedIntervals.push_back(intervals[i++]);
    }

    std::cout << "> All interval(s) without a match or split:\n> ";
    for (const auto& row : revisedIntervals)
    {
        std::cout << "[ ";
        for (const auto& col : row)
        {
            std::cout << col << ", ";
        }
        std::cout << "] ";
    }
    std::cout << "\n(Only 100% smaller pairs added, ie: rh is smaller)\n";

    std::cout << "\n---[ add match || modify split (1 interval) ]---\n";
    std::cout << "Start [ " << intervals[i][lh] << ", "
                            << intervals[i][rh] << " ] (index " << i << ")\n";
    std::cout << "Seek [ " << newInterval[lh] << ", " << newInterval[rh] << " ]\n";
    while (i < intervals.size() && intervals[i][lh] <= newInterval[rh])
    {
        newInterval[lh] = std::min(newInterval[lh], intervals[i][lh]);
        newInterval[rh] = std::max(newInterval[rh], intervals[i][rh]);
        ++i;
    }
    revisedIntervals.push_back(newInterval);

    std::cout << "> ";
    for (const auto& row : revisedIntervals)
    {
        std::cout << "[ ";
        for (const auto& col : row)
        {
            std::cout << col << ", ";
        }
        std::cout << "] ";
    }
    std::cout << "\n(Assess [min, max], modify if needed, add)\n";

    std::cout << "\n---[ add tail interval(s) ]---\n";
    std::cout << "Start [ " << intervals[i][lh] << ", "
                            << intervals[i][rh] << " ] (index " << i << ")\n";
    while (i < intervals.size())
    {
        revisedIntervals.push_back(intervals[i++]);
    }

    std::cout << "> ";
    for (const auto& row : revisedIntervals)
    {
        std::cout << "[ ";
        for (const auto& col : row)
        {
            std::cout << col << ", ";
        }
        std::cout << "] ";
    }

    return revisedIntervals;
}

// what about a pure vector approach for simplicity? it's doable to generate
// an output of the overlapping range, but because the requested output is a
// merged vector, if there is shifting across pairs (very likely) would
// need to generate new vector anyways... so probably not be worth O(n^2)
// to assess the two dimensional vector
std::vector<std::vector<int>> insertAltOne(std::vector<std::vector<int>>& intervals,
                                            std::vector<int>& newInterval)
{

    int lh = newInterval[0];
    int rh = newInterval[1];

    for (int i = 0; i < intervals.size(); ++i) {
        for (int j = 0; j < intervals.size(); ++j) {
            std::cout << "[i][j]: " << intervals[i][j] << "\n";
            // while lh match (exact or between),
            // assess j++ against rh (exact or between)
            if (lh == intervals[i][j]) {
            } else if (lh > intervals[i][j] && lh < (intervals[i][j + 1])){
                std::cout << "lh [ " << lh << " ] : between j and j + 1.\n\n";
            } else {
                std::cout << "lh [ " << lh << " ] : no match.\n\n";
            }
        }
    }
    return intervals;
}

// EOF