// 0011

#include <iostream>
#include <vector>

using namespace std;

int max_area(vector<int>& lines) {

    int left = 0;
    int right = lines.size() - 1;

    // area = height * width;
    int the_max = min(lines[left], lines[right]) * (right - left);

    while (left < right) {

        int new_area = min(lines[left], lines[right]) * (right - left);
        the_max = max(the_max, new_area);

        // move toward middle; spec is 'most' water, so favor taller sides
        if (lines[left] < lines[right]) {
            left++;
        } else {
            right--;
        }
    }

    return the_max;
}


//--[ test driver ]--//
int main() {
    vector<int> lines {1,8,6,2,5,4,8,3,7};

    cout << "\nInput: [ "; for (auto i: lines) { cout << i << ", "; } cout << "]\n";

    int result = max_area(lines);

    std::cout << "Expected: [ 49 (8 x 8 container holds 7 * 7) ]\n";
    std::cout << "Result:   [ " << result << " ]\n";

    return 0;
}
// eof
