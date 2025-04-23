#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct Node
{
    int x;
    int y;
};


int main() {
    // Please write your code here.

    //freopen_s(new FILE*, "input.txt", "r", stdin);

    int cnt;
    cin >> cnt;

 
    int nX, nY, direct, degree;
    Node start, pivot;
    stack<Node> map;
    stack<Node> carry;
    
    set<pair<int, int>> visited;

    //0우 1상 2좌 3하
    int transX[4] = {0, -1, 0, 1};
    int transY[4] = {1, 0, -1, 0};
    
    for (int i = 0; i < cnt; i++) {
        stack<Node> dotList;
        cin >> start.x >> start.y >> direct >> degree;
        dotList.push(start);

        //좌표변환
        nX = start.x + transX[direct];
        nY = start.y + transY[direct];
        if (nX > 101 || nX < 0 || nY > 101 || nY < 0) continue;
        dotList.push({ nX , nY });
        
        pivot = { nX , nY }; // 마지막에 그려지는 점. 이 점을 기준으로 계속 시계방향으로 돌림
        
        // 점 찍자
        for (int j=0; j< degree; j++) {
            // 점 리스트의 값을 캐리로 복사해와서 변환 후 맵에 추가.
            // 변환 (상>우, 우>하, 하>좌, 좌>상), 변화 크기는 같고 양/음만 바뀜
            int left, right;
            carry = dotList;
            int exp = dotList.size();
            for (int k = 0; k < exp; k++) { // 기준 점과의 차이값을 변환. 마지막 점과 더한 값이 새로 찍힐 점이 됨
                Node currentNode = carry.top();
                carry.pop();
                left = 0;
                right = 0;
                if (currentNode.x - pivot.x != 0) {
                    right = -(currentNode.x - pivot.x);
                }
                if (currentNode.y - pivot.y != 0) {
                    left = (currentNode.y - pivot.y);
                }
                //end와 더해서 dotList에 추가하고 마지막에 들어갈 점은새로운 end가 됨
                if (pivot.x - currentNode.x == 0 && pivot.y - currentNode.y == 0) continue;
                dotList.push({ pivot.x + left, pivot.y + right});
                
            }
            pivot = dotList.top();  //마지막에 그려지는게 새로운 피벗이 됨.
            
        }


        while (!dotList.empty()) {
            Node temp = dotList.top();
            
            if (visited.count({ temp.x, temp.y }) == 0) {
                map.push(temp);
                visited.insert({ temp.x, temp.y }); // 좌표 기억
            }
            dotList.pop();
        
        }
    }

    //101X101을 다 검사하기에 괜찮은가. ㄴㄴ
    

    //cf> 좌(0,-1), 상(-1,0), 우(0,1), 하(1,0)
    /*   1 2
         3 4     */
    int diaX[4] = {-1, -1, 1, 1};       //1 2 3 4
    int diaY[4] = {-1, 1, -1, 1};
    int count = 0;
    //점을 하나씩 검사. 한 점 기준으로 네 방향 다 검사 완료했으면 중간 기준으로 쓴 점을 pop().
    while (!map.empty()) {
        Node mid = map.top();
        //대각선 검사를 해볼까?
        for (int i = 0; i < 4; i++) {
            int cmpX = diaX[i] + mid.x;
            int cmpY = diaY[i] + mid.y;

            //i값으로 어느방향 판단하는지 알 수 있음 사분면처럼 판단.
            if (i == 0 || i == 1) {
                if (visited.count({ cmpX, cmpY }) != 0) { //존재하면 검사.
                    if (visited.count({ cmpX + 1, cmpY }) != 0 && visited.count({ mid.x - 1, mid.y }) != 0)
                        count++;
                }
            }
            else {
                if (visited.count({ cmpX, cmpY }) != 0) { //존재하면 검사.
                    if (visited.count({ cmpX - 1, cmpY }) != 0 && visited.count({ mid.x + 1, mid.y }) != 0)
                        count++;
                }
            }

        }
        //중복 카운팅 처리...
        visited.erase({ mid.x, mid.y });    // >> 다음에 사각형 고려요소로 안쓰게 될 것임
        map.pop(); //존재하는 점을 하나씩 검사.
    }

    cout << count;

    

    return 0;
}