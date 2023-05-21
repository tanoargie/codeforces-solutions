#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void advanceCounting(vector<int> &original, bool &alreadyConverged) {
  /* for (int i = 0; i < original.size(); i++) { */
  /*   cout << "o_i: " << original[i] << endl; */
  /* } */
  vector<int> counting(original.size() + 1, 0);
  for (int i = 0; i < original.size(); i++) {
    counting[original[i]] = counting[original[i]] + 1;
  }
  bool isConverging = true;
  for (int i = 0; i < original.size(); i++) {
    if (original[i] != counting[original[i]]) {
      isConverging = false;
    }
    original[i] = counting[original[i]];
  }
  if (isConverging) {
    alreadyConverged = true;
  }
}

int getResult(vector<int> &original, vector<vector<int>> &pastRuns, int step,
              int position, bool &alreadyConverged) {
  /* cout << step << " " << alreadyConverged << endl << "---" << endl; */
  if (step < pastRuns.size()) {
    return pastRuns[step][position - 1];
  } else if (alreadyConverged) {
    return pastRuns[pastRuns.size() - 1][position - 1];
  } else {
    advanceCounting(original, alreadyConverged);
    pastRuns.push_back(original);
    return getResult(original, pastRuns, step, position, alreadyConverged);
  }
}

int main() {
  int numberOfTests;
  int numberOfQueries;
  cin >> numberOfTests;
  int arraySize;
  int aNumber;
  vector<int> results;
  for (int i = 0; i < numberOfTests; ++i) {
    cin >> arraySize;
    vector<int> original;
    int maxStep = 0;
    for (int j = 0; j < arraySize; ++j) {
      cin >> aNumber;
      original.push_back(aNumber);
    }
    cin >> numberOfQueries;
    vector<pair<int, int>> queries;

    vector<vector<int>> pastRuns;
    pastRuns.push_back(original);
    int xi, ki;
    for (int k = 0; k < numberOfQueries; ++k) {
      cin >> xi >> ki;
      pair<int, int> query = make_pair(xi, ki);
      queries.push_back(query);
    }

    bool alreadyConverged = false;
    for (int k = 0; k < numberOfQueries; k++) {
      results.push_back(getResult(original, pastRuns, queries[k].second,
                                  queries[k].first, alreadyConverged));
    }
  }

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
