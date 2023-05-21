#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getFortuneTelling(long long n, long long x, long long y) {}

int main() {
  long long t, n, x, y;
  vector<string> res;

  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> x >> y;
    res.push_back(getFortuneTelling(n, x, y));
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }
  return 0;
}
