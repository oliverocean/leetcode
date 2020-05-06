#include <iostream>
#include <vector>

int maxArea(std::vector<int>& lines);

int main() {

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

// submitted, runtime 16ms @ 96.33%, memory 9.8mb @ 85.57%
int maxArea(std::vector<int>& lines) {

    int lh = 0;
    int rh = static_cast<int>(lines.size() - 1); // if vector is 10 units wide, size=10 but INDEX=9
    int theMaxArea = std::min(lines[lh], lines[rh]) * (rh - lh); // initialize to outermost lines

    while (lh < rh) {

//        //-------------------------------------//
//        std::cout << "lh: " << lh << "\n";
//        std::cout << "rh: " << rh << "\n";
//        std::cout << "h * w = ?\n";
//        std::cout << std::min(lines[lh], lines[rh]) << " * "
//                  << (rh - lh) << " = "
//                  << std::min(lines[lh], lines[rh]) * (rh - lh);
//        std::cout << "\n-------------------\n";
//        //-------------------------------------//

        int aNewArea = std::min(lines[lh], lines[rh]) * (rh - lh);

        // could also do this instead of the if statement:
        // theMaxArea = std::max(theMaxArea, aNewArea);
        if (theMaxArea < aNewArea) {
            theMaxArea = aNewArea;
        }

        if (lines[lh] < lines[rh]) {
            ++lh;
        } else {
            --rh;
        }
    }
    return theMaxArea;
}