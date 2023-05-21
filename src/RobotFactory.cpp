#include <algorithm>
#include <iostream>

using namespace std;

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

int n, m;
int matrix[1000][1000];
int vis[1000][1000];
int streak = 0;
int components = 0;
int res[1000000];
int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j) {
  vis[i][j] = 1;
  streak++;
  for (int k = 0; k < 4; k++) {
    int ni = moves[k][0] + i;
    int nj = moves[k][1] + j;
    if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
        !(CHECK_BIT(matrix[i][j], 3 - k))) {
      /* cout << "if1: " << matrix[i][j] << " " << matrix[ni][nj] << " " << k */
      /*      << endl; */
      if (!vis[ni][nj]) {
        dfs(ni, nj);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        int beforeBreakingStreak = streak;
        dfs(i, j);
        res[components] = streak - beforeBreakingStreak;
        /* cout << components << " " << streak << " " << beforeBreakingStreak */
        /*      << " " << i << " " << j << " " << endl; */
        components++;
      }
    }
  }

  sort(res, res + components, greater<int>());
  for (int i = 0; i < components; i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
