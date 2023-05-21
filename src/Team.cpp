#include <iostream>

using namespace std;

int main() {
    int numberOfProblems;
    cin >> numberOfProblems;
    int decision;
    int counterLine = 0;
    int restart = 0;
    int res = 0;
    for (int i = 0; i < numberOfProblems*3; ++i) {
        cin >> decision;
        counterLine += decision;
        restart++;
        if (counterLine == 2) {
            res++;
            counterLine = 0;
        }  
        if (restart == 3) {
            restart = 0;
            counterLine = 0;
        }
    }

    cout << res << endl;

    return 0;
}
