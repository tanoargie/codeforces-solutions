#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getReverseAndConcatenate(string &s, int k) {
  if (k == 0)
    return 1;
  bool isPalindrome = true;
  for (int i = 0; i < s.size() && isPalindrome; i++) {
    if (!(s[s.size() - 1 - i] == s[i])) {
      isPalindrome = false;
    }
  }
  if (isPalindrome)
    return 1;
  return 2;
}

int main() {
  int t, n, k;
  string s;
  vector<int> res;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> n >> k;
    cin >> s;
    res.push_back(getReverseAndConcatenate(s, k));
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }
  return 0;
}
