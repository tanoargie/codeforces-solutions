#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int getBobScore(const vector<vector<int>> &matrix) {
  int numberOfColumns = matrix[0].size();

  int upperRow = 0;
  for (int i = 0; i < numberOfColumns; ++i) {
    upperRow += matrix[0][i];
  }

  int lowerRow = 0;
  upperRow -= matrix[0][0];
  int maxBetweenRows = max(lowerRow, upperRow);
  int res = maxBetweenRows;
  for (int i = 1; i < numberOfColumns; ++i) {
    lowerRow += matrix[1][i - 1];
    upperRow -= matrix[0][i];
    maxBetweenRows = max(lowerRow, upperRow);
    if (maxBetweenRows < res) {
      res = maxBetweenRows;
    }
  }

  return res;
}

int main() {
  int numberOfCases;
  vector<int> results;
  cin >> numberOfCases;
  int m;
  int number;
  for (int i = 0; i < numberOfCases; ++i) {
    cin >> m;
    vector<vector<int>> matrix;
    for (int k = 0; k < 2; ++k) {
      vector<int> row;
      for (int j = 0; j < m; ++j) {
        cin >> number;
        row.push_back(number);
      }
      matrix.push_back(row);
    }
    results.push_back(getBobScore(matrix));
  }

  for (int i = 0; i < results.size(); ++i) {
    cout << results[i] << endl;
  }

  return 0;
}
