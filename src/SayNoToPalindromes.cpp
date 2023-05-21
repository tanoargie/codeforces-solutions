#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  int n;
  int m;
  string s;
  vector<int> results;
  cin >> n >> m >> s;
  vector<string> startingTriplets = {"abc", "acb", "bca", "bac", "cab", "cba"};
  vector<vector<int>> possibleChains(6, vector<int>(n + 1, 0));
  for (int i = 0; i < possibleChains.size(); ++i) {
    int sumDiff = 0;
    for (int j = 0; j < n; ++j) {
      if (startingTriplets[i][j % 3] == s[j]) {
        possibleChains[i][j + 1] = sumDiff;
      } else {
        possibleChains[i][j + 1] = sumDiff + 1;
        sumDiff++;
      }
    }
  }

  int start;
  int end;
  for (int i = 0; i < m; ++i) {
    cin >> start >> end;
    int res = n;
    for (int j = 0; j < 6; ++j) {
      res = min(res, possibleChains[j][end] - possibleChains[j][start - 1]);
    }
    results.push_back(res);
  }

  for (int i = 0; i < results.size(); ++i) {
    cout << results[i] << endl;
  }

  return 0;
}
