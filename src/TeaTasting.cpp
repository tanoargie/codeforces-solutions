#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int n, vector<int> &sorts, const vector<int> &maxDrinking,
           vector<long long> &result) {
  int startDrinker = 0;
  int endSorts = n - 1;
  while (startDrinker < n && endSorts >= 0) {
    for (int i = startDrinker, j = 0; i < n && j <= endSorts; i++, j++) {
      int take = min(maxDrinking[i], sorts[j]);
      result[i] += take;
      sorts[j] -= take;
    }
    startDrinker++;
    endSorts--;
  }
}

int main() {
  int t;
  int n;
  cin >> t;
  int sortAndDrinking;
  vector<vector<long long> > results;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<int> sorts;
    vector<int> maxDrinking;
    for (int j = 0; j < n; j++) {
      cin >> sortAndDrinking;
      sorts.push_back(sortAndDrinking);
    }
    for (int k = 0; k < n; k++) {
      cin >> sortAndDrinking;
      maxDrinking.push_back(sortAndDrinking);
    }
    vector<long long> result(n, 0);
    solve(n, sorts, maxDrinking, result);
    results.push_back(result);
  }
  for (int i = 0; i < t; i++) {
    vector<long long> result = results[i];
    for (int j = 0; j < result.size(); j++) {
      cout << result[j] << " ";
    }
    cout << endl;
  }

  return 0;
}
