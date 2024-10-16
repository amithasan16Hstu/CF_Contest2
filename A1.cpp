#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        // Ensure p1 <= p2 <= p3
        if (p1 > p2 || p2 > p3) {
            cout << -1 << endl;
            continue;
        }

        int total_points = p1 + p2 + p3;
        if (total_points % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        int draws = (p1 + p2 + p3) / 2 - max({p1, p2, p3});

        // Check if the calculated draws are valid
        if (draws < 0 || (p1 + p2 + p3 - 2 * draws) % 4 != 0) {
            cout << -1 << endl;
        } else {
            cout << draws << endl;
        }
    }

    return 0;
}
