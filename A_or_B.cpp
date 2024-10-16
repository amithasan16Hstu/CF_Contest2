#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    
    while (T--) {
        int X, Y; 
        cin >> X >> Y;
        
        
        int pointsA_first = max(0, 500 - 2 * X) + max(0, 1000 - 4 * (X + Y));
        
        int pointsB_first = max(0, 1000 - 4 * Y) + max(0, 500 - 2 * (X + Y));
        
        int max_points = max(pointsA_first, pointsB_first);
        
        cout << max_points << endl;
    }
    
    return 0;
}
