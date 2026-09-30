#include <iostream>

using namespace std;

int N, answer = -1;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    // Please write your code here.
    for(int i=0;i<N;i++)
        for(int j=0; j<=N-3; j++)
            answer = max(answer, grid[i][j]+grid[i][j+1]+grid[i][j+2]);
        

    cout << answer;

    return 0;
}