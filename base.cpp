#include <bits/stdc++.h>
using namespace std;

void printBinary(int N) {
    if (N > 1) {
        printBinary(N / 2);
    }
    cout << (N % 2);
}

int main() {
    int T;
    cin >> T;
    vector<int> numbers(T);

    for (int i = 0; i < T; ++i) {
        cin >> numbers[i];
    }

   
    for (int i = 0; i < T; ++i) {
        printBinary(numbers[i]);
        cout << endl;
    }

    return 0;
}
