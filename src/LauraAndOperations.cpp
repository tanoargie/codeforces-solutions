#include <iostream>
#include <vector>

using namespace std;

bool sameParity(const int a, const int b) {
  return (a % 2 == 1 && b % 2 == 1) || (a % 2 == 0 && b % 2 == 0);
}

vector<int> process(const vector<int> &input) {
  vector<int> result(3, 0);
  if (sameParity(input[0], input[1]) && sameParity(input[1], input[2])) {
    result[0] = 1;
    result[1] = 1;
    result[2] = 1;
  } else if (sameParity(input[0], input[1])) {
    result[2] = 1;
  } else if (sameParity(input[0], input[2])) {
    result[1] = 1;
  } else if (sameParity(input[1], input[2])) {
    result[0] = 1;
  }
  return result;
}

int main() {
  int numberOfCases;
  cin >> numberOfCases;
  vector<vector<int> > results;
  int input;
  for (int i = 0; i < numberOfCases; i++) {
    vector<int> onesTwosThrees = vector<int>(3);
    for (int j = 0; j < 3; j++) {
      cin >> input;
      onesTwosThrees[j] = input;
    }
    results.push_back(process(onesTwosThrees));
  }
  for (int i = 0; i < results.size(); i++) {
    for (int j = 0; j < results[i].size(); j++) {
      cout << results[i][j] << " ";
    }
    cout << endl;
  }
}
