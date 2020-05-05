#include <iostream>
#include <vector>
#include <set>

// function prototypes
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>&);

int main() {

    std::cout << "\n---[ input ]---\n";

    std::cout << "> Original Intervals\n";

    //std::vector<std::vector<int>> intervals;
    //std::vector<std::vector<int>> intervals {{1, 4}, {0, 2}, {3, 5}};
    std::vector<std::vector<int>> intervals {{1, 4}, {0, 2}, {5, 4}, {3, 5}};
    //std::vector<std::vector<int>> intervals {{1, 4}, {4, 5}, {3, 4}};
    //std::vector<std::vector<int>> intervals {{7, 8}, {9, 14}, {13, 18}, {20, 22}, {21, 26}, {28, 30}};
    //std::vector<std::vector<int>> intervals {{1, 2}, {3, 6}, {8, 12}, {15, 18}};
    for (const auto& row : intervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }

    std::cout << "\n\n---[ debug ]---\n";
    std::vector<std::vector<int>> revisedIntervals = merge(intervals);

    std::cout << "\n\n---[ output ]---\n";
    for (const auto& row : revisedIntervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }
    std::cout << "\n";

    return 0;
}

// second submission, runtime 16ms @ 94%, memory 11.7 @ 100%
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {

    if (intervals.empty()) return std::vector<std::vector<int>>{};

    sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> result;
    result.push_back(intervals[0]); // initialize with first interval

    int lh = 0;
    int rh = 1;

    for (auto& i : intervals ) {
        if (i[lh] > result.back()[rh]) {
            result.push_back(i);
        } else {
            result.back()[rh] = std::max(i[rh], result.back()[rh]);
        }
    }
    return result;
}

//// initial attempt - works (for single pass) but doesn't cover all test cases
//// (multiple splits per interval) and is more complex than needed.
//std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
//
//    if (intervals.empty()) return std::vector<std::vector<int>>{{}};
//
//    // sorting intervals using a lambda
//    sort(intervals.begin(), intervals.end(), [&](std::vector<int>& a, std::vector<int>& b){return a[0] < b[0];});
//    std::vector<std::vector<int>> revisedIntervals;
//    std::vector<int> splitInterval = {INT_MAX, INT_MIN};
//
//    int i = 0;
//    int lh = 0;
//    int rh = 1;
//
//    while (i < intervals.size() - 1) {
//        if (intervals[i][rh] < intervals[i + 1][lh]) {
//            revisedIntervals.push_back(intervals[i++]);
//        } else if (intervals[i][lh] < intervals[i + 1][rh]) {
//            splitInterval[lh] = std::min(intervals[i][lh], intervals[i + 1][lh]);
//            splitInterval[rh] = std::max(intervals[i][rh], intervals[i + 1][rh]);
//            revisedIntervals.push_back(splitInterval);
//            i += 2;
//        }
//    }
//    // add on tail
//    while (i < intervals.size()) {
//        revisedIntervals.push_back(intervals[i++]);
//    }
//
//    return revisedIntervals;
//}