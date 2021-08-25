#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/* bool canYouReproduceStringByJudgingChar(int pos, string s, string t, map<string, bool> &alreadyTestedStrings) { */
/*     if (s == t) { */
/*         return true; */
/*     } else if (s.size() <= t.size()) { */
/*         return false; */
/*     } else if (pos > s.size() || pos > 2) { */
/*         return false; */
/*     } else if (alreadyTestedStrings.find(s) != alreadyTestedStrings.end())  { */
/*         return alreadyTestedStrings[s]; */
/*     } */ 
/*     if (pos > 0) { */
/*         string newS = s.substr(0, pos - 1); */
/*         newS.append(s.substr(pos + 1)); */
/*         alreadyTestedStrings[s] = canYouReproduceStringByJudgingChar(pos - 1, newS, t, alreadyTestedStrings) || canYouReproduceStringByJudgingChar(pos + 1, s, t, alreadyTestedStrings); */
/*     } else { */
/*         string newS = s.substr(pos + 1, s.size()); */
/*         alreadyTestedStrings[s] = canYouReproduceStringByJudgingChar(pos, newS, t, alreadyTestedStrings) || canYouReproduceStringByJudgingChar(pos + 1, s, t, alreadyTestedStrings); */
/*     } */
/*     return alreadyTestedStrings[s]; */
/* } */

bool canYouReproduceString(string s, string t) {
    bool match = false;
    int lastS = s.size() - 1;
    int lastT = t.size() - 1;

    while (lastS >= 0 && lastT >= 0) {
        if (s[lastS] == t[lastT]) {
            lastS--;
            lastT--;
        } else {
            lastS = lastS - 2;
        }
    }

    if (lastT < 0) {
        match = true;
    }

    return match;
}

int main() {
    int numberOfCases;
    cin >> numberOfCases;
    vector<string> results;
    string s;
    string t;
    for (int i = 0; i < numberOfCases; ++i) {
        cin >> s >> t;
        /* map<string, bool> alreadyTestedStrings; */
        if (canYouReproduceString(s,t)) {
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
