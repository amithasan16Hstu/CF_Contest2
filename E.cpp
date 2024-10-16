#include<bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;

    for(int k=0;k<tst;k++) {
        int n;
        cin >> n;

        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<long long> Odd(n + 1, 0), Even(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Odd[i + 1] = Odd[i] + (i % 2 == 0 ? v[i] : 0);
            Even[i + 1] = Even[i] + (i % 2 != 0 ? v[i] : 0);
        }

      
        bool found = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((k - i) % 2 == 0 && Odd[k + 1] - Odd[i] == Even[k + 1] - Even[i]) {
                    found = 1;
                    break;
                }
                if ((k - i) % 2 != 0 && Odd[k + 1] - Odd[i] == Even[k] - Even[i]) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

      
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}
