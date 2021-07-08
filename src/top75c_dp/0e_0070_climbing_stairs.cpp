// 0070
#include <iostream>
#include <vector>

using namespace std;

// standard dp
int climb_stairs_(int n) {

    vector<int>sum(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + sum[i - 2];
    }

    return sum[n];
}

// fibonacci sum
int climb_stairs(int n) {

    int sum = 1;
    int previous = 1;

    for (int i = 1; i < n; i++) {
        sum += previous;
        previous = sum - previous;
    }

    return sum;
}

//--[ test driver ]--- */
int main() {

    int test = 12;
    cout << "test: [ " << test << " ]\n";
    cout << "result: \n" << climb_stairs(test) << "\n";

    return 0;
}

// eof
