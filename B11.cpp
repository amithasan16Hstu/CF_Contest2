#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        int maxA = X + 2;

       
        int maxB = Y + 1;

       
        if (maxA >= Y && X <= maxB) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
