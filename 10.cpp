#include <iostream>
using namespace std;
int main() {
    int value = 10;
    int *ptr = &value;  // Declare a pointer and assign it the address of value

    cout << "Initial value: " << value << endl;
    cout << "Address of value: " << &value << endl;
    cout << "Pointer (ptr) holds address: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    // Modify the value through the pointer
    *ptr = 20;
    
    cout << "\nAfter modifying value through pointer:" << endl;
    cout << "Value: " << value << endl;
    cout << "Value pointed to by ptr: " << *ptr <<endl;

    return 0;
}
