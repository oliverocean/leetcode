// 0238

#include <iostream>
#include <vector>

using namespace std;

//--[ two vectors ]--//
vector<int> product_except_self(vector<int>& nums) {

    int len = nums.size();

    vector<int> left(len); // each item = product of all items to left of itself
    left[0] = 1; // first pivot is left-most index; recall 1 * n = n
    for (int a = 1; a < len; a++) {
        left[a] = left[a - 1] * nums[a - 1];
    }

    vector<int> right(len); // each item = product of all items to right of itself
    right[len - 1] = 1; // first pivot is right-most index; recall 1 * n = n
    for (int b = (len - 2); b >= 0; b--) {
        right[b] = right[b + 1] * nums[b + 1];
    }

    vector<int> result(len);
    cout << "[ "; for (auto i: result) { cout << i << ", "; } cout << "]\n";
    for (int c = 0; c < len; c++) {
        result[c] = left[c] * right[c];
        cout << "[ "; for (auto i: result) { cout << i << ", "; } cout << "]\n";
    }

    return result;
}

//--[ single vector ]--//
vector<int> product_except_self_a(vector<int>& nums) {

    int len = nums.size();

    vector<int> left(len);
    left[0] = 1;
    for (int a = 1; a < len; a++) {
        left[a] = left[a - 1] * nums[a - 1];
    }

    // eval right and replace left along the way
    int right = 1;
    for (int b = (len - 1); b >= 0; b--) {
        left[b] = left[b] * right;
        right *= nums[b];
    }

    return left;
}

//--[ test driver ]--//
int main() {
    vector<int>input {1, 2, 3, 4, 5, 6, 7};

    cout << "--[ input ]--\n";
    cout << "[ "; for (auto i: input) { cout << i << ", "; } cout << "]\n";

    vector<int> output = product_except_self(input);

    cout << "\n---[ output ]---\n";
    cout << "[ "; for (auto i: output) { cout << i << ", "; } cout << "]\n";

    return 0;
}

/*
---> 2 Vector
> left [ 1, 0, 0, 0, 0, 0, 0, ]
> left [ 1, 1, 0, 0, 0, 0, 0, ]
> left [ 1, 1, 2, 0, 0, 0, 0, ]
> left [ 1, 1, 2, 6, 0, 0, 0, ]
> left [ 1, 1, 2, 6, 24, 0, 0, ]
> left [ 1, 1, 2, 6, 24, 120, 0, ]
> left [ 1, 1, 2, 6, 24, 120, 720, ]
---
> right [ 0, 0, 0, 0, 0, 0, 1, ]
> right [ 0, 0, 0, 0, 0, 7, 1, ]
> right [ 0, 0, 0, 0, 42, 7, 1, ]
> right [ 0, 0, 0, 210, 42, 7, 1, ]
> right [ 0, 0, 840, 210, 42, 7, 1, ]
> right [ 0, 2520, 840, 210, 42, 7, 1, ]
> right [ 5040, 2520, 840, 210, 42, 7, 1, ]

> result [ 0, 0, 0, 0, 0, 0, 0, ]
> result [ 5040, 0, 0, 0, 0, 0, 0, ]
> result [ 5040, 2520, 0, 0, 0, 0, 0, ]
> result [ 5040, 2520, 1680, 0, 0, 0, 0, ]
> result [ 5040, 2520, 1680, 1260, 0, 0, 0, ]
> result [ 5040, 2520, 1680, 1260, 1008, 0, 0, ]
> result [ 5040, 2520, 1680, 1260, 1008, 840, 0, ]
> result [ 5040, 2520, 1680, 1260, 1008, 840, 720, ]

---> 1 Vector
> left [ 1, 0, 0, 0, 0, 0, 0, ]
> left [ 1, 1, 0, 0, 0, 0, 0, ]
> left [ 1, 1, 2, 0, 0, 0, 0, ]
> left [ 1, 1, 2, 6, 0, 0, 0, ]
> left [ 1, 1, 2, 6, 24, 0, 0, ]
> left [ 1, 1, 2, 6, 24, 120, 0, ]
> left [ 1, 1, 2, 6, 24, 120, 720, ]
-----
> right [ 1 ]
   left [ 1, 1, 2, 6, 24, 120, 720, ]
> right [ 7 ]
   left [ 1, 1, 2, 6, 24, 120, 720, ]
> right [ 42 ]
   left [ 1, 1, 2, 6, 24, 840, 720, ]
> right [ 210 ]
   left [ 1, 1, 2, 6, 1008, 840, 720, ]
> right [ 840 ]
   left [ 1, 1, 2, 1260, 1008, 840, 720, ]
> right [ 2520 ]
   left [ 1, 1, 1680, 1260, 1008, 840, 720, ]
> right [ 5040 ]
   left [ 1, 2520, 1680, 1260, 1008, 840, 720, ]
> right [ 5040 ]
   left [ 5040, 2520, 1680, 1260, 1008, 840, 720, ]

[ 5040, 2520, 1680, 1260, 1008, 840, 720, ]
*/

// eof
