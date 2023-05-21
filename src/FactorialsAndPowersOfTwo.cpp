#include <iostream>
#include <math.h>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int ones(long long input) {
  if (input > 2) {
    if (input % 2 == 0) {
      return ones(input / 2);
    } else {
      return ones(input / 2) + 1;
    }
  } else if (input == 0) {
    return 0;
  } else {
    return 1;
  }
}

long long factorial(long long input) {
  if (input == 1 || input == 0) {
    return 1;
  } else {
    return input * factorial(input - 1);
  }
}

int main() {
  int numberCases;
  cin >> numberCases;
  vector<long long> results;
  vector<long long> factorials;
  int fact = 0;
  while (fact < 15) {
    factorials.push_back(factorial(fact));
    fact++;
  }
  vector<pair<long long, int>> factorialSums;
  for (int i = 0; i < factorials.size(); i++) {
    int factorialsSumsATM = factorialSums.size();
    pair<long long, int> sumAndTerms = make_pair(factorials[i], 1);
    factorialSums.push_back(sumAndTerms);
    for (int j = 0; j < factorialsSumsATM; j++) {
      long long newSum = factorialSums[j].first + factorials[i];
      int newTerms = factorialSums[j].second + 1;
      pair<long long, int> newSumAndTerms = make_pair(newSum, newTerms);
      factorialSums.push_back(newSumAndTerms);
    }
  }

  for (int i = 0; i < numberCases; i++) {
    long long number;
    cin >> number;
    int minTerms = ones(number);
    // cout << "ones: " << min << endl;
    for (int j = 0;
         factorialSums[j].first <= number && j < factorialSums.size(); j++) {
      int currentTerms =
          ones(number - factorialSums[j].first) + factorialSums[j].second;
      if (currentTerms < minTerms) {
        // cout << factorialSums[j].first << " " << factorialSums[j].second << "
        // "
        //      << number - factorialSums[j].first << endl;
        minTerms = currentTerms;
      }
    }
    results.push_back(minTerms);
  }

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
