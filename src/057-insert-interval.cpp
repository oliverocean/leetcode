#include <iostream>
#include <vector>
#include <set>

// function prototypes
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>&, std::vector<int>&);

int main() {

    std::cout << "\n---[ input ]---\n";

    std::cout << "> Original Intervals\n";
    //std::vector<std::vector<int>> intervals {{1, 3}, {6, 9}};
    //std::vector<std::vector<int>> intervals {{3, 4}, {5, 6}, {7, 8}, {9, 10}};
    //std::vector<std::vector<int>> intervals {{2, 3}, {4, 5}, {6, 7}, {8, 9}};
    std::vector<std::vector<int>> intervals {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    for (const auto& row : intervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }

    std::cout << "\n> New Interval ";
    std::vector<int> newInterval {5, 6};
    //std::vector<int> newInterval {5, 8};
    //std::vector<int> newInterval {10, 11};
    //std::vector<int> newInterval {5, 9};
    std::cout << "[ ";
    for (const auto& item : newInterval) { std::cout << item << ", "; } std::cout << "]\n";

    //std::cout << "\n---[ debug ]---\n";

    std::vector<std::vector<int>> revisedIntervals = insert(intervals, newInterval);

    std::cout << "\n\n---[ output ]---\n";
    for (const auto& row : revisedIntervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }
    std::cout << "\n";

    return 0;
}

// runtime: 16ms @ 83.03%, memory: 11.8mb @ 100%
// realizing the reqs ask to modify the existing vector
// this solution returns a new vector instead... :|
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {

    std::vector<std::vector<int>>revisedIntervals;

    int i{0};
    int lh{0};
    int rh{1};

    while (i < intervals.size() && intervals[i][rh] < newInterval[lh]) {
        revisedIntervals.push_back(intervals[i++]);
    }

    while (i < intervals.size() && intervals[i][lh] <= newInterval[rh]) {
        newInterval[lh] = std::min(newInterval[lh], intervals[i][lh]);
        newInterval[rh] = std::max(newInterval[rh], intervals[i][rh]);
        ++i;
    }

    revisedIntervals.push_back(newInterval);

    while (i < intervals.size()) {
        revisedIntervals.push_back(intervals[i++]);
    }

    return revisedIntervals;
}


//// solution with debug comments
//std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
//
//    std::vector<std::vector<int>>revisedIntervals;
//
//    int i = 0;
//    int lh = 0;
//    int rh = 1;
//
//    std::cout << "\n---[ add head interval(s) ]---\n";
//    std::cout << "Start [ " << intervals[i][lh] << ", " << intervals[i][rh] << " ] (index " << i << ")\n";
//    std::cout << "Seek [ " << newInterval[lh] << ", " << newInterval[rh] << " ]\n";
//    while (i < intervals.size() && intervals[i][rh] < newInterval[lh]) {
//        revisedIntervals.push_back(intervals[i++]);
//    }
//
//    std::cout << "> All interval(s) without a match or split:\n> ";
//    for (const auto& row : revisedIntervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }
//    std::cout << "\n(Only 100% smaller pairs added, ie: rh is smaller)\n";
//
//    std::cout << "\n---[ add match || modify split (1 interval) ]---\n";
//    std::cout << "Start [ " << intervals[i][lh] << ", " << intervals[i][rh] << " ] (index " << i << ")\n";
//    std::cout << "Seek [ " << newInterval[lh] << ", " << newInterval[rh] << " ]\n";
//    while (i < intervals.size() && intervals[i][lh] <= newInterval[rh]) {
//        newInterval[lh] = std::min(newInterval[lh], intervals[i][lh]);
//        newInterval[rh] = std::max(newInterval[rh], intervals[i][rh]);
//        ++i;
//    }
//    revisedIntervals.push_back(newInterval);
//
//    std::cout << "> ";
//    for (const auto& row : revisedIntervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }
//    std::cout << "\n(Assess [min, max], modify if needed, add)\n";
//
//    std::cout << "\n---[ add tail interval(s) ]---\n";
//    std::cout << "Start [ " << intervals[i][lh] << ", " << intervals[i][rh] << " ] (index " << i << ")\n";
//    while (i < intervals.size()) {
//        revisedIntervals.push_back(intervals[i++]);
//    }
//
//    std::cout << "> ";
//    for (const auto& row : revisedIntervals) { std::cout << "[ "; for (const auto& col : row) { std::cout << col << ", "; } std::cout << "] "; }
//
//    return revisedIntervals;
//}

// partially completed idea below
//vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//
//    // Origin: [1, 3], [6, 9]
//    // New:        [2, 5]
//
//    // compare first value of new vector to origin vector
//    // see if a match is found OR if a smaller number is found, check if the next one is bigger
//    // in either scenario, note the location in the origin vector (the match or smaller + 1)
//    // compare the second value of the new vector to origin vector similarly
//    // (match found) OR if a bigger number is found, check if the previous one is smaller
//
//    // thought: dump all vals into a map, assess from both ends (since ordered)
//    // erase matching (between) items, dump vals back into new vector?
//    // potentially efficient with memory space.
//
//    // int stream from a two dimension vector?
//    // could initialize set and then use double for loop to insert into set each iteration
//
//    std::set<int> theSet;
//
//    for (const auto& row : intervals) {
//        for (const auto& col : row) {
//            theSet.insert(col);
//        }
//    }
//
//    std::cout << "> theSet: [ ";
//    for (const auto& i: theSet) {
//        std::cout << i << ", ";
//    }
//    std::cout << "]\n";
//
//    int lh = newInterval[0];
//    int rh = newInterval[1];
//
//    // corner case, partial matches on ends of intervals
//    // so rh matches only value on/near head
//    // or lh matches value on/near tail
//
//    // search l-to-r for lh in the intervals vector
//    // if either match found OR between two numbers
//    // do the same for the upper limit
//    // immediately find those in the set and erase them
//
//    for (auto& row : intervals) {
//        for (auto& col : row) {
//            if (lh == col) {
//                int reverse = col;
//                while (theSet.find(reverse) != theSet.end()) {
//                    theSet.erase(reverse--);
//                }
//            } else if (rh == col) {
//                int forward = col;
//                while (theSet.find(forward) != theSet.end()) {
//                    theSet.erase(forward++);
//                }
////            } else if (lh > col) {
////                int reverse = col - 1;
////                while (theSet.find(reverse) != theSet.end()) {
////                    theSet.erase(reverse--);
////                }
////                //theSet.insert(lh);
////            } else if (rh < col) {
////                int forward = col - 1;
////                while (theSet.find(forward) != theSet.end()) {
////                    theSet.erase(forward++);
////                }
//                //theSet.insert(rh);
//            }
//        }
//    }
//
//
//    std::cout << "> revised: [ ";
//    for (const auto& i: theSet) {
//        std::cout << i << ", ";
//    }
//    std::cout << "]\n";
//
//    return intervals;
//}





// general strategy:
// compare first value of new vector to origin vector
// see if a match is found OR if a smaller number is found, check if the next one is bigger
// in either scenario, note the location in the origin vector (the match or smaller + 1)
// compare the second value of the new vector to origin vector similarly
// (match found) OR if a bigger number is found, check if the previous one is smaller
//
// what about a pure vector approach for simplicity?
//
// after looking through, it's doable to generate an output of the
// overlapping range, but because the requested output is a merged
// vector, if there is shifting across pairs (very likely) would
// need to generate new vector anyways... so probably not be worth
// big O n^2 to assess the two dimensional vector
//
//vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//
//    int lh = newInterval[0];
//    int rh = newInterval[1];
//
//    for (int i = 0; i < intervals.size(); ++i) {
//        for (int j = 0; j < intervals.size(); ++j) {
//            std::cout << "[i][j]: " << intervals[i][j] << "\n";
//            // while lh match (exact or between),
//            // assess j++ against rh (exact or between)
//            // be cool to do this recursively?
//            if (lh == intervals[i][j]) {
//            } else if (lh > intervals[i][j] && lh < (intervals[i][j + 1])){
//                std::cout << "lh [ " << lh << " ] : between j and j + 1.\n\n";
//            } else {
//                std::cout << "lh [ " << lh << " ] : no match.\n\n";
//            }
//        }
//    }
//    return intervals;
//}