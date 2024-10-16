#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    
    while (T--) {
        int X, N;
        cin >> X >> N;
        
      
        int total_planes_required = (N + 99) / 100;
        
        
        int new_planes_needed = total_planes_required - X;
      
        if (new_planes_needed < 0) {
            new_planes_needed = 0;
        }
        
        cout << new_planes_needed << endl;
    }
    
    return 0;
}
