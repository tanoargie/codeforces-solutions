#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

int distance(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int maxDistance(pair<int, int> point, int n, int m) {
  pair<int, int> bottomLeft = make_pair(0, 0);
  pair<int, int> bottomRight = make_pair(0, m);
  pair<int, int> topLeft = make_pair(n, 0);
  pair<int, int> topRight = make_pair(n, m);

  int maxBottom =
      max(distance(point, bottomLeft), distance(point, bottomRight));
  int maxTop = max(distance(point, topLeft), distance(point, topRight));
  return max(maxBottom, maxTop);
}

vector<int> getDistanceBetweenRT(int n, int m) {
  vector<int> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pair<int, int> point = make_pair(i, j);
      res.push_back(maxDistance(point, n - 1, m - 1));
    }
  }

  sort(res.begin(), res.end());

  return res;
}

int main() {
  int t, n, m;
  cin >> t;
  vector<vector<int>> resOfRes;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m;
    resOfRes.push_back(getDistanceBetweenRT(n, m));
  }
  for (int j = 0; j < resOfRes.size(); j++) {
    for (int i = 0; i < resOfRes[j].size(); i++) {
      cout << resOfRes[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
