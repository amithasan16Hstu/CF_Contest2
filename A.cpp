#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int min_val = min(x, y);
        int max_val = max(x, y);

        cout << min_val << " " << max_val << endl;
    }

    return 0;
}
