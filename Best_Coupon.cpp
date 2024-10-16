#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int X; 
        cin >> X;

        int discount1 = X * 0.10; 
        int discount2 = 100;      

        
        int max_discount = max(discount1, discount2);

        cout << max_discount << endl;
    }

    return 0;
}
