#include <iostream>

using namespace std;

int main() {
    int quantity;
    int min;

    cin >> quantity >> min;

    int number;
    int res = 0;
    for (int i = 0; i < min; ++i) {
        cin >> number;
        if (number > 0) res++;
    }
    int rightFrontier = number;
    cin >> number;
    while (min < quantity && number > 0 && number == rightFrontier) {
        min++;
        res++;
        if (min < quantity) cin >> number;
    }

    cout << res << endl;

    return 0;
}
