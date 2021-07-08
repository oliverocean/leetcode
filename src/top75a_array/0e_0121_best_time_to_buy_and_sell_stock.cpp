// 0121
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_profit(vector<int>& prices) {

    int buy = INT_MAX;
    int profit = 0;

    for (int price : prices) {
        buy = min(buy, price);
        profit = max(profit, price - buy);
    }

    return profit;
}

//--[ Kanade's Algorithm ]--//
int max_profit_a(vector<int>& prices) {

    int price = 0;
    int profit = 0;

    for (int n = 1; n < prices.size(); n++) {
        price += prices[n] - prices[n - 1];
        price = max(price, 0);
        profit = max(profit, price);
    }

    return profit;
}

//--[ function test driver ]--//
int main() {

    vector<int>input {7, 1, 5, 3, 6, 4};

    cout << "\n---[ input ]---\n";
    cout << "daily price: [ ";
    for (auto i: input) { cout << i << ", "; }
    cout << "]\n";

    int output = max_profit(input);
    cout << "\n---[ output ]---\n";
    cout << "result: [ $" << output << " ]\n";

    return 0;
}
// eof
