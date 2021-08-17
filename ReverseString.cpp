#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool hasAPathFrom(int start,const string s, string t, bool alreadyWentToLeft) {
    if (start >= s.size()) {
        return false;
    }
    if (start < 0) {
        return false;
    }
    if (s[start] == t[0]) {
        if (t.size() == 1) {
            return true;
        }
        if ((!alreadyWentToLeft && hasAPathFrom(start + 1, s, t.substr(1), false)) || hasAPathFrom(start - 1, s, t.substr(1), true)) {
            return true;
        }
    }
    return false;
}

int main() {
    int numberOfCases;
    vector<string> results;
    cin >> numberOfCases;
    string s;
    string t;
    for (int i = 0; i < numberOfCases; ++i) {
        cin >> s >> t;
        bool found = false;
        for (int j = 0; !found && j < s.size(); j++) {
            if (hasAPathFrom(j, s, t, false)) {
                found = true;
            }
        }
        if (found) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }
    }
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }
    return 0;
}
