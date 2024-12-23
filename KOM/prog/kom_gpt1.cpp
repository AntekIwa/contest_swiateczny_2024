#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct State {
    int x, y, energy;
};

bool canReach(const vector<vector<int>>& grid, int n, int m, int k, int maxDiff) {
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    queue<State> q;
    q.push({0, 0, k});
    visited[0][0][k] = true;

    const int dx[] = {0, 1};
    const int dy[] = {1, 0};

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int energy = current.energy;

        if (x == n - 1 && y == m - 1) {
            return true;
        }

        for (int d = 0; d < 2; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1) {
                continue;
            }

            int heightDiff = grid[nx][ny] - grid[x][y];
            if (heightDiff > maxDiff) {
                continue;
            }

            if (grid[nx][ny] == 0) {
                if (!visited[nx][ny][k]) {
                    visited[nx][ny][k] = true;
                    q.push({nx, ny, k});
                }
            } else if (heightDiff > 0) {
                if (energy > 0 && !visited[nx][ny][energy - 1]) {
                    visited[nx][ny][energy - 1] = true;
                    q.push({nx, ny, energy - 1});
                }
            } else {
                if (!visited[nx][ny][energy]) {
                    visited[nx][ny][energy] = true;
                    q.push({nx, ny, energy});
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int left = 0, right = 1000000, result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canReach(grid, n, m, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result == -1) {
        cout << "NIE" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
