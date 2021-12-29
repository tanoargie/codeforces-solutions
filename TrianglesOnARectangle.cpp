#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> res;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    int maxArea = 0;
    for (int j = 0; j < 4; j++) {
      int numberOfPoints;
      int numberMin, numberMax;
      cin >> numberOfPoints;
      cin >> numberMin;
      for (int p = 1; p < numberOfPoints; p++) {
        cin >> numberMax;
      }
      if (j < 2) {
        int area = h * (numberMax - numberMin);
        if (area > maxArea)
          maxArea = area;
      } else {
        int area = w * (numberMax - numberMin);
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
