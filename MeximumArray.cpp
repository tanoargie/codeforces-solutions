#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> meximumArray(vector<int> &a) {
  vector<int> res;
  vector<int> mexArray(a.size(), 0);
  int mexRes = 0;
  unordered_set<int> appeared;
  for (int i = a.size() - 1; i >= 0; i--) {
    appeared.insert(a[i]);
    while (appeared.count(mexRes)) {
      mexRes++;
    }
    mexArray[i] = mexRes;
  }

  appeared.clear();
  mexRes = 0;
  int cut = 0;
  for (int j = 0; j < a.size(); j++) {
    appeared.insert(a[j]);
    while (appeared.count(mexRes)) {
      mexRes++;
    }
    if (mexRes == mexArray[cut]) {
      /* cout << "mr: " << mexRes << " " << cut << " " << j << endl; */
      res.push_back(mexRes);
      mexRes = 0;
      cut = j + 1;
      appeared.clear();
    }
  }

  return res;
}

int main() {
  int t, n, ai;
  vector<vector<int>> resOfRes;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<int> a;
    vector<int> res;
    for (int j = 0; j < n; j++) {
      cin >> ai;
      a.push_back(ai);
    }
    resOfRes.push_back(meximumArray(a));
  }

  for (int i = 0; i < resOfRes.size(); i++) {
    cout << resOfRes[i].size() << endl;
    for (int j = 0; j < resOfRes[i].size(); j++) {
      cout << resOfRes[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
