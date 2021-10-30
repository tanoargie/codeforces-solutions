#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int matrix[1000][1000];
int vis[1000][1000];
int currNumber;
int k = 0;
int res[1000000];
int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j) { vis[i][j] = 1; }

int main() {
  cin >> n >> m;

  // O(1000*1000)
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j]) {
      }
    }
  }

  sort(res, res + k, greater<int>());
  for (int i = 0; i < k; i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
