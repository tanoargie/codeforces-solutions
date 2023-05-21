#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

/*
supongamos que hay 3 aristas x, y, z desde un mismo vértice
=> x, y, z primos. También x+y primo, z+y primo y x+z primo
=> si x impar => y par => z impar
=> pero entonces x es impar y z es impar
pero entonces x+z no es primo.
=> así con todas las combinaciones.

CONCLUSIÓN:
=> si un vértice tiene por lo menos 3 aristas no hay solución
*/
void dfs(map<int, vector<int>> &adjacency, int vertex, vector<bool> &discovered,
         map<pair<int, int>, int> &weights, int last = 3) {
  discovered[vertex] = true;
  for (int i = 0; i < adjacency[vertex].size(); i++) {
    int adjacent = adjacency[vertex][i];
    if (!discovered[adjacent]) {
      weights[make_pair(vertex, adjacent)] = last;
      weights[make_pair(adjacent, vertex)] = last;
      if (last == 2) {
        dfs(adjacency, adjacent, discovered, weights, 3);
      } else {
        dfs(adjacency, adjacent, discovered, weights, 2);
      }
    }
  }
}

int main() {
  int t, n, u, v;
  cin >> t;
  vector<vector<int>> resRes;

  for (int i = 0; i < t; i++) {
    cin >> n;
    map<int, vector<int>> adjacency;
    vector<bool> discovered(n, false);
    bool possible = true;
    vector<pair<int, int>> order;
    for (int j = 0; j < n - 1; j++) {
      cin >> u >> v;
      adjacency[u].push_back(v);
      adjacency[v].push_back(u);
      order.push_back(make_pair(u, v));
    }
    int leaf;
    for (map<int, vector<int>>::iterator it = adjacency.begin();
         it != adjacency.end() && possible; it++) {
      if (it->second.size() > 2) {
        possible = false;
      } else if (it->second.size() == 1) {
        leaf = it->first;
      }
    }
    if (possible) {
      map<pair<int, int>, int> weights;
      vector<int> res;
      dfs(adjacency, leaf, discovered, weights);
      for (int p = 0; p < order.size(); ++p) {
        res.push_back(weights[order[p]]);
      }
      resRes.push_back(res);
    } else {
      resRes.push_back(vector<int>(1, -1));
    }
  }
  for (int j = 0; j < resRes.size(); j++) {
    for (int i = 0; i < resRes[j].size(); i++) {
      cout << resRes[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
