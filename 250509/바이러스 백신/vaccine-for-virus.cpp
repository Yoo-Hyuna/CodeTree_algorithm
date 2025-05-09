#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct node {
    int x, y;
};

int n, m;
vector<vector<int>> map;
vector<node> hospitals;
int minTime = INT_MAX;

// 바이러스를 제거하는 BFS
int spreadVirus(vector<int>& selected) {
    vector<vector<int>> time(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<node> q;

    // 선택된 병원들을 큐에 넣고 방문 처리
    for (int idx : selected) {
        node start = hospitals[idx];
        q.push(start);
        visited[start.x][start.y] = true;
    }

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        node curr = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            if (map[nx][ny] == 0) {
                time[nx][ny] = time[curr.x][curr.y] + 1;
            } else { // 병원
                time[nx][ny] = time[curr.x][curr.y];
            }
            q.push({ nx, ny });
        }
    }

    int maxTime = 0;

    // 모든 바이러스 제거 가능 여부 확인
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 0) {
                if (!visited[i][j]) return -1; // 바이러스 못 없앰
                maxTime = max(maxTime, time[i][j]);
            }
        }
    }
    return maxTime;
}

// 병원 조합 DFS
void dfs(int depth, int start, vector<int>& selected) {
    if (depth == m) {
        int result = spreadVirus(selected);
        if (result != -1) {
            minTime = min(minTime, result);
        }
        return;
    }

    for (int i = start; i < hospitals.size(); ++i) {
        selected.push_back(i);
        dfs(depth + 1, i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                hospitals.push_back({ i, j });
            }
        }
    }

    vector<int> selected;
    dfs(0, 0, selected);

    if (minTime == INT_MAX) cout << -1;
    else cout << minTime;

    return 0;
}
