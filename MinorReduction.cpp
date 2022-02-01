#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getMinorReduction(string &x) {
  string max = x;
  int max0 = max[0] - '0';
  int max1 = max[1] - '0';
  int sumMax = max0 + max1;
  string sumMaxString = to_string(sumMax);
  max.replace(0, 2, sumMaxString);
  bool foundMaxLoop = false;
  string maxLoop;
  for (int i = 1; i < x.size() - 1; ++i) {
      int xi = x[i] - '0';
      int xi1 = x[i+1] - '0';
      int sum = xi + xi1;
      if (sum >= 10) {
          /* cout << sum << " " << i << endl; */
          maxLoop = x;
          string sumString = to_string(sum);
          maxLoop.replace(i, 2, sumString);
          foundMaxLoop = true;
      }
  }
  if (foundMaxLoop) return maxLoop;

  return max;
}

int main() {
  int t;
  cin >> t;
  vector<string> res;
  for (int i = 0; i < t; ++i) {
    string x;
    cin >> x;

    res.push_back(getMinorReduction(x));
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }

  return 0;
}
