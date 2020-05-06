#include <iostream>
#include <vector>

int search(std::vector<int>&, int);

int main() {

    std::vector<int> items{1, 0, 3, 5, 6, 7, 8, 44, 66, 9, 12};
    int target{6};

    std::cout << "\n --- results --- \n";
    std::cout << search(items, target);

    return 0;
}

// binary search
int search(std::vector<int>& items, int target) {

    if (items.empty()) return -1; // corner case

    int low{};
    int high{static_cast<int>(items.size() - 1)};
    int guess{};

    while (low <= high) {
        guess = low + (high - low) / 2;

        if (items[guess] == target) {
            return guess;
        } else if (items[guess] < target) {
            low = guess + 1;
        } else {
            high = guess - 1;
        }
    }

    // per requirements, return -1 if nothing is found
    return -1;
}