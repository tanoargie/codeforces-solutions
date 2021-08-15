#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    int difficulty;
    int res = 1;
    int strikeAtTheMoment = 1;
    cin >> difficulty;
    int before = difficulty;
    for (int i = 1; i < cases; ++i) {
        cin >> difficulty;
        if (difficulty <= before*2) {
            strikeAtTheMoment++;
        } else {
            strikeAtTheMoment = 1;
        }
        if (strikeAtTheMoment > res) {
            res = strikeAtTheMoment;
        }
        before = difficulty;
    }

    cout << res << endl;

    return 0;
}
