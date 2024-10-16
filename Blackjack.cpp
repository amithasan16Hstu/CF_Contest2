#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        
        int required_sum = 21;
        int C = required_sum - A - B; 
        if (C >= 1 && C <= 10) {
            cout << C << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
