#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

bool compare_function(pair<long long, long long> p1,
                      pair<long long, long long> p2) {
  return p1.first < p2.first;
}

int main() {
  long long numberOfTests;
  cin >> numberOfTests;
  vector<string> results;
  for (long long i = 0; i < numberOfTests; i++) {
    long long numberOfMonsters;
    long long genosAttack;
    long long maxHealth = 0;
    cin >> numberOfMonsters;
    cin >> genosAttack;

    long long health;
    vector<long long> healths;
    for (long long j = 0; j < numberOfMonsters; j++) {
      cin >> health;
      if (health > maxHealth) {
        maxHealth = health;
      }
      healths.push_back(health);
    }

    long long power;
    vector<long long> powers;
    for (long long j = 0; j < numberOfMonsters; j++) {
      cin >> power;
      powers.push_back(power);
    }

    vector<pair<long long, long long> > orderedPowerHealth;
    for (long long j = 0; j < numberOfMonsters; j++) {
      orderedPowerHealth.push_back(make_pair(powers[j], healths[j]));
    }

    sort(orderedPowerHealth.begin(), orderedPowerHealth.end(),
         compare_function);

    long long itHealth = 0;
    long long genosAccumAttack = 0;
    while (itHealth < orderedPowerHealth.size() && genosAttack > 0) {
      genosAccumAttack += genosAttack;
      if (genosAccumAttack > maxHealth) {
        break;
      }
      while (itHealth < orderedPowerHealth.size() &&
             genosAccumAttack >= orderedPowerHealth.at(itHealth).second) {
        itHealth++;
      }
      if (orderedPowerHealth.size() == itHealth) {
        break;
      }
      long long weakestPower = orderedPowerHealth.at(itHealth).first;
      genosAttack -= weakestPower;
    }

    if (genosAccumAttack > maxHealth || itHealth == orderedPowerHealth.size()) {
      results.push_back("YES");
    } else {
      results.push_back("NO");
    }
  }

  for (long long i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
