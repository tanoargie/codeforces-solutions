#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int processForEachChar(char charWithMaxAppearances, string &word) {
  // cout << charWithMaxAppearances << endl;
  int count = 0;

  int lastPositionNotErased = -1;
  int lastPositionErased = -2;
  vector<bool> erasedPositions(word.size(), false);
  bool allTheSame = false;
  while (!allTheSame) {
    allTheSame = true;
    for (int i = 0; i < word.size(); i++) {
      if (word[i] != charWithMaxAppearances && !erasedPositions[i] &&
          lastPositionNotErased > lastPositionErased) {
        allTheSame = false;
        erasedPositions[i] = true;
        lastPositionErased = i;
      } else if (!erasedPositions[i]) {
        lastPositionNotErased = i;
      }
    }
    if (allTheSame) {
      break;
    }
    // for (int i = 0; i < erasedPositions.size(); i++) {
    //   cout << erasedPositions[i] << " ";
    // }
    // cout << endl;
    lastPositionNotErased = -1;
    lastPositionErased = -2;
    count++;
  }

  return count;
}

int process(string &word, map<char, int> &alphabetAppearances) {
  set<char> uniqueChars;
  for (int i = 0; i < word.size(); i++) {
    uniqueChars.insert(word[i]);
  }

  vector<int> results;
  while (!uniqueChars.empty()) {
    char current = *uniqueChars.begin();
    results.push_back(processForEachChar(current, word));
    uniqueChars.erase(uniqueChars.begin());
  }

  int min = word.size();
  for (int i = 0; i < results.size(); i++) {
    if (results[i] < min) {
      min = results[i];
    }
  }

  return min;
}

int main() {
  int numberOfTests;
  vector<int> results;
  string word;

  cin >> numberOfTests;
  for (int i = 0; i < numberOfTests; i++) {
    cin >> word;
    map<char, int> alphabetAppearances;
    results.push_back(process(word, alphabetAppearances));
  }

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
