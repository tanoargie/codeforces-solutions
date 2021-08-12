#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    vector<string> res;

    string word;
    for (int i = 0; i < cases; ++i) {
        cin >> word;

        if (word.size() > 10) {
            res.push_back(word[0] + to_string(word.size() - 2) + word[word.size() - 1]);
        } else {
            res.push_back(word);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
