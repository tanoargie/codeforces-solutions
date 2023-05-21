#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<long long> res;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long w, h;
    cin >> w >> h;
    long long maxArea = 0;
    for (int j = 0; j < 4; j++) {
      long long numberOfLong;
      long long numberMin, numberMax;
      cin >> numberOfLong;
      cin >> numberMin;
      for (long long p = 1; p < numberOfLong; p++) {
        cin >> numberMax;
      }
      if (j < 2) {
        long long area = h * (numberMax - numberMin);
        if (area > maxArea)
          maxArea = area;
      } else {
        long long area = w * (numberMax - numberMin);
        if (area > maxArea)
          maxArea = area;
      }
    }

    res.push_back(maxArea);
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }

  return 0;
}
