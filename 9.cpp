#include <iostream>
using namespace std;
// Function that swaps the values of two integers using reference variables
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Before swapping: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Call the swap function with x and y
    swap(x, y);

    cout << "After swapping: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
