#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> buckets(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> buckets[i];
        }

        // Sort the buckets in descending order
        std::sort(buckets.rbegin(), buckets.rend());

        // Calculate the total number of squares
        long long totalSquares = 0;
        for (int i = 0; i < n; ++i) {
            totalSquares += buckets[i];
        }

        // Check if a square can be formed
        if (totalSquares % n == 0 && buckets[0] <= totalSquares / n) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
