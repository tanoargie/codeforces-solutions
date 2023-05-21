#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int numberOfTests;
  cin >> numberOfTests;
  vector<string> results;
  for (int i = 0; i < numberOfTests; i++) {
    int numberOfMonsters;
    int genosAttack;
    cin >> numberOfMonsters;
    cin >> genosAttack;

    deque<pair<int, int> > orderedMonsters;
    int health;
    vector<int> healths;
    for (int j = 0; j < numberOfMonsters; j++) {
      cin >> health;
      healths.push_back(health);
    }
    // for (int j = 0; j < numberOfMonsters; j++) {
    //   cout << healths[j] << " ";
    // }

    int power;
    vector<int> powers;
    for (int j = 0; j < numberOfMonsters; j++) {
      cin >> power;
      powers.push_back(power);
    }
    // cout << powers.size() << endl;
    // for (int j = 0; j < numberOfMonsters; j++) {
    //   cout << powers[j] << " ";
    // }

    // cout << "size1" << endl;
    for (int j = 0; j < numberOfMonsters; j++) {
      pair<int, int> powerAndHealth = make_pair(powers[j], healths[j]);
      if (orderedMonsters.empty()) {
        orderedMonsters.emplace_back(powerAndHealth);
      } else {
        pair<int, int> weakestMonster = orderedMonsters.front();
        if (weakestMonster.first > powerAndHealth.first) {
          orderedMonsters.emplace_front(powerAndHealth);
        } else if (weakestMonster.first == powerAndHealth.first &&
                   weakestMonster.second < powerAndHealth.second) {
          orderedMonsters.emplace_front(powerAndHealth);
        } else {
          orderedMonsters.emplace_back(powerAndHealth);
        }
      }
    }

    auto monster = orderedMonsters.front();
    while (!orderedMonsters.empty() || genosAttack > 0) {
      for (int j = 0; j < orderedMonsters.size(); j++) {
        int monsterHealth = orderedMonsters[j].second;
        orderedMonsters[j].second = monsterHealth - genosAttack;
      }
      // for (auto j = orderedMonsters.begin(); j != orderedMonsters.end(); ++j)
      // {
      //   cout << j->second << " ";
      // }
      while (monster.second <= 0) {
        orderedMonsters.pop_front();
        if (!orderedMonsters.empty()) {
          monster = orderedMonsters.front();
        }
      }
      cout << "size1" << endl;
      pair<int, int> weakestMonster = orderedMonsters.front();
      genosAttack -= weakestMonster.first;
    }
    if (orderedMonsters.empty()) {
      results.push_back("NO");
    } else {
      results.push_back("YES");
    }
  }

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}
