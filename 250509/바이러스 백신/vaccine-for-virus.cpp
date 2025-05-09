#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <climits>

using namespace std;


int maxxx;
int minnn = INT_MAX;
int n, m, dist;
vector<vector<int>> map;
vector<vector<int>> countt;
vector<vector<bool>> visited;
queue<int> distttt;

struct node {
    int x;
    int y;
};

vector<node> hp;

//바이러스 제거
int dellll(string str) {
    queue<node> q;

    for (int i = 0; i < m;i++) {
        q.push(hp[str[i] - '0']);
    }

    int dx[] = { -1,0,1,0 };
    int dy[] = { 0,1,0,-1 };

    node temp;
    int nx, ny, pre;
    dist = 1;

    while (!q.empty()) {
        temp = q.front();
        if (visited[temp.x][temp.y] == true) break;
        else visited[temp.x][temp.y] = true;
        q.pop();
        for (int i = 0; i < 4;i++) {
            //시계방향으로 검사
            nx = temp.x + dx[i];
            ny = temp.y + dy[i];
            pre = countt[temp.x][temp.y];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; //(2,5) 확인
            // 0 바이러스, 1 벽, 2 병원
            if (map[nx][ny] == 0 && visited[nx][ny] == false && countt[nx][ny]==0) {
                countt[nx][ny] = pre+1;
                q.push({ nx,ny });
            } 
        }
    }

    ///dfs문 안에서는 최대 값을 찾고 main에서 결과 값 모임에서 최소값을 찾아서 출력
    maxxx = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && map[i][j] == 0) {
                return -1;
                break;
            }
            if (countt[i][j] >= maxxx) {
                maxxx = countt[i][j];
            }
        }
    }
    return maxxx;
}


void dfs(int dep, int start, int hpCnt, string str) {
    if (dep >= m) {
        //경우의수를 인자로 입력, 거리 결과 받아옴
        distttt.push(dellll(str));
        //if (dist <= minnn) {
            //minnn = dist;
        //}

        countt = vector<vector<int>>(n, vector<int>(n, 0));
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        return;
    }

    for (int i = start; i < hpCnt; i++) {
        dfs(dep + 1, i + 1, hpCnt, str + to_string(i));
    }
}


int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);

    int input;
    int cnt = 1;
    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(n, 0));
    countt = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));



    // 0 바이러스, 1 벽, 2 병원
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            map[i][j]= input;
            if (input == 2)
                hp.push_back({ i,j });  //전체 병원 목록이 들어감
        }
    }

    //병원 조합 선택 bfs
    dfs(0, 0, hp.size(),"");
    //dfs(3, 0, hp.size(),"123");


    //다 검사 후 최소값 출력. 다만, 모든 경우의 수가 -1이면 -1출력
    bool allcasearenotmeaning = true;
    while (!distttt.empty()) {
        if (distttt.front() != -1) {
            if (distttt.front() <= minnn) minnn = distttt.front();
            allcasearenotmeaning = false;
        }
        distttt.pop();
    }
    if (allcasearenotmeaning == true) cout << -1;
    else cout << minnn;


    return 0;
}