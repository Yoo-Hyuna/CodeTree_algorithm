#include <iostream>
#define X first
#define Y second
using namespace std;

int R, C, answer;
char grid[15][15]; // 0~14
pair<int, int> pivot;

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    char start = grid[0][0], end = grid[R-1][C-1];
    if(start == end){
        cout << 0;
        return 0;
    }

    for (int i = 1; i < R-1; i++) {
        for (int j = 1; j < C-1; j++) {
            if(grid[i][j] != start){
                pivot = {i,j};

                for(int k = i+1; k < R-1; k++){
                    for(int l = j+1; l < C-1; l++){
                        if(grid[k][l] != grid[pivot.X][pivot.Y])
                            answer++;
                    }
                }
            }
        }
    }
    cout << answer;

    return 0;
}