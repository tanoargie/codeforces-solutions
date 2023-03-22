#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  int n;
  int ai;
  vector<pair<int, int> > results;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<int> a;
    for (int j = 0; j < n; j++) {
      cin >> ai;
      a.push_back(ai);
    }
    int l = 1;
    int r = n;
    int max = n;
    int min = 1;
    while (l < r && (a[l - 1] == max || a[l - 1] == min || a[r - 1] == max ||
                     a[r - 1] == min)) {
      if (a[l - 1] == min) {
        l++;
        min++;
      } else if (a[l - 1] == max) {
        l++;
        max--;
      } else if (a[r - 1] == max) {
        r--;
        max--;
      } else if (a[r - 1] == min) {
        r--;
        min++;
      }
    }
    if (l == r) {
      results.push_back(make_pair(-1, -1));
    } else {
      results.push_back(make_pair(l, r));
    }
  }
  for (int i = 0; i < t; i++) {
    if (results[i].first == -1) {
      cout << -1 << endl;
    } else {
      cout << results[i].first << " " << results[i].second << endl;
    }
  }
  return 0;
}
