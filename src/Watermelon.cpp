#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;

    if (number == 2) {
        cout << "NO" << endl;
    } else if (number % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
