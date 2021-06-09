/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Container With Most Water
 * @index: 011
 * @difficulty: medium
 * @topic: array, two pointers
 * @reqs: https://leetcode.com/problems/container-with-most-water/
 * @brief:
 *     > Given n non-negative integers a1, a2, ..., an , where each
 *       represents a point at coordinate (i, ai).
 *     > n vertical lines are drawn such that the two endpoints of
 *       line i is at (i, ai) and (i, 0).
 *     > Find two lines, which together with x-axis forms a container,
 *       such that the container contains the most water.
 * @example:
 *     The vertical lines [ ] below are represented by the array
 *     [ 1, 8, 6, 2, 5, 4, 8, 3, 7 ]. In this case, the max area
 *     of water (at and below '---') the container can hold is [49].
 *       - 9 -
 *       - 8 -     [x]                 [ ]
 *       - 7 -     [x]-----------------[ ]-----[x]
 *       - 6 -     [x] [ ]             [ ]     [x]
 *       - 5 -     [x] [ ]     [ ]     [ ]     [x]
 *       - 4 -     [x] [ ]     [ ] [ ] [ ]     [x]
 *       - 3 -     [x] [ ]     [ ] [ ] [ ] [ ] [x]
 *       - 2 -     [x] [ ] [ ] [ ] [ ] [ ] [ ] [x]
 *       - 1 - [ ] [x] [ ] [ ] [ ] [ ] [ ] [ ] [x]
 *         h   (1) (8) (6) (2) (5) (4) (8) (3) (7)
 * @note: You may not slant the container and n is at least 2.
 */

#include <iostream>
#include <vector>

/* ---[ function prototypes ]--- */
int maxArea(std::vector<int>& lines);
int maxAreaDebug(std::vector<int>& lines);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int> lines {1,8,6,2,5,4,8,3,7};

    std::cout << "\nInput: [ ";
    for (auto i: lines) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    //std::cout << "\n------ Debug ------\n";
    int result = maxArea(lines);

    std::cout << "Expected: [ 49 ]\n";
    std::cout << "Result:   [ " << result << " ]\n";

    return 0;
}

/* ---[ final approach ]--- */
/* runtime: 16ms @ 96%, memory 9.8mb @ 86% */
int maxArea(std::vector<int>& lines)
{
    int lh = 0;
    int rh = static_cast<int>(lines.size() - 1);

    int theMaxArea = std::min(lines[lh], lines[rh]) * (rh - lh);

    while (lh < rh)
    {
        int aNewArea = std::min(lines[lh], lines[rh]) * (rh - lh);

        theMaxArea = std::max(theMaxArea, aNewArea);

        if (lines[lh] < lines[rh])
        {
            ++lh;
        }
        else
        {
            --rh;
        }
    }
    return theMaxArea;
}

/* ---[ final approach with debug output and notes ]--- */
int maxAreaDebug(std::vector<int>& lines)
{
    int lh = 0;

    // if vector is 10 units wide, size=10 but INDEX=9
    int rh = static_cast<int>(lines.size() - 1);

    // initialize to outermost lines
    int theMaxArea = std::min(lines[lh], lines[rh]) * (rh - lh);

    while (lh < rh)
    {
        /* ------------------------------------- */
        std::cout << "lh: " << lh << "\n";
        std::cout << "rh: " << rh << "\n";
        std::cout << "h * w = ?\n";
        std::cout << std::min(lines[lh], lines[rh]) << " * "
                  << (rh - lh) << " = "
                  << std::min(lines[lh], lines[rh]) * (rh - lh);
        std::cout << "\n-------------------\n";
        /* ------------------------------------- */

        int aNewArea = std::min(lines[lh], lines[rh]) * (rh - lh);
        theMaxArea = std::max(theMaxArea, aNewArea);
        // could also do this instead of max:
        // if (theMaxArea < aNewArea) { theMaxArea = aNewArea; }

        if (lines[lh] < lines[rh])
        {
            ++lh;
        }
        else
        {
            --rh;
        }
    }
    return theMaxArea;
}

// EOF