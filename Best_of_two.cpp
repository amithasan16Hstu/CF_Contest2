#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int A1, A2, A3, B1, B2, B3;
        cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

        
        int Alice[3] = {A1, A2, A3};
        int Bob[3] = {B1, B2, B3};

        
        sort(Alice, Alice + 3);
        sort(Bob, Bob + 3);

        
        int AliceScore = Alice[1] + Alice[2];
        int BobScore = Bob[1] + Bob[2];

        
        if (AliceScore > BobScore) {
            cout << "Alice" << endl;
        } else if (BobScore > AliceScore) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }

    return 0;
}
