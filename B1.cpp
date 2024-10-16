#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        
        bool is_possible = (s.front() != s.back());

        if (is_possible) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
