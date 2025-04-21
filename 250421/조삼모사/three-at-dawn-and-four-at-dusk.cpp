#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int Card = 0;
int minnn = INT_MAX;

vector<bool> check;
vector<int> caseeam;
vector<int> caseepm;
vector<vector<int>> vec;

//업무강도 구하기
int ackack(int num) {
    int cnt = 0;
    int cntp = 0;
    for (int i = 0; i < num; i++) {
        if (check[i] == true) {
            caseeam[cnt] = i + 1;
            cnt++;
        }
        else {
            caseepm[cntp] = i + 1;
            cntp++;
        }
    }

    int row, col;
    int aaa = 0;
    int ppp = 0;
    vector<bool> visited(Card, false);
    for (int i = 0; i < Card; i++) {
        row = caseeam[i]-1;
        visited[i] = true;
        for (int j = 0; j < Card; j++) {
            if (visited[j] == false) {
                col = caseeam[j]-1;
                aaa += vec[row][col];
            }
        }
        visited[i] = false;
    }

    for (int i = 0; i < Card; i++) {
        row = caseepm[i]-1;
        visited[i] = true;
        for (int j = 0; j < Card; j++) {
            if (visited[j] == false) {
                col = caseepm[j]-1;
                ppp += vec[row][col];
            }
        }
        visited[i] = false;
    }

    return abs(aaa - ppp);


}

//아침, 저녁 경우의수 나누기
void dfs(int dep, int start, int num) {
    if (dep >= Card) {
        int fsfs = ackack(num);
        if (minnn >= fsfs)
            minnn = fsfs;
        return;
    }

    for (int i = start; i < num; i++) {
        check[i] = true;
        dfs(dep + 1, i + 1, num);
        check[i] = false;

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen_s(new FILE*, "input.txt", "r", stdin);
    // Please write your code here.
    int num = 0;

    cin >> num;
    Card = num / 2;
    vec = vector<vector<int>>(num, vector<int>(num, 0));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> vec[i][j];
        }
    }

    check = vector<bool>(num, false);
    caseeam = vector<int>(Card, 0);
    caseepm = vector<int>(Card, 0);

    //경우의 수 나누는 작업 필요
    dfs(0, 0, num);

    cout << minnn;
    return 0;
}