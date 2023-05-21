#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int numberOfCases;
  vector<int> results;
  cin >> numberOfCases;
  int wordSize;
  string word;
  for (int i = 0; i < numberOfCases; i++) {
    cin >> wordSize;
    cin >> word;
    int totalPossibilities = wordSize - 1;
    for (int j = 1; j < wordSize - 1; j++) {
      if (word[j - 1] == word[j + 1]) {
        totalPossibilities--;
      }
    }
    results.push_back(totalPossibilities);
  }

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
