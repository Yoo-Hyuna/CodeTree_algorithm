#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> vec;    //숫자 배열
vector<int> path;
int maxx = 0;
int minn = 0;
int cmp = 0;
int cnt =0;

int op(int total) {
    int cal = vec[0];
    for (int i = 0; i < total; i++) {
        if (path[i] == 1) {
            cal += vec[i+1];
        }
        else if (path[i] == 2) {
            cal -= vec[i+1];
        }
        else {
            cal *= vec[i+1];
        }    
    }

    return cal;
}

void generate(vector<int>& nums, vector<int>& counts, vector<int>& path, int total) {
    if (path.size() == total) {
        cmp = op(total);
        if(cnt==0){
            maxx = cmp;
            minn = cmp;
        } else{
            if (cmp >= maxx) maxx = cmp;
            if (cmp <= minn) minn = cmp;
        }
       
        cnt++;
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (counts[i] > 0) {
            counts[i]--;             // 사용
            path.push_back(nums[i]); // 추가
            generate(nums, counts, path, total); // 재귀
            path.pop_back();         // 백트래킹
            counts[i]++;             // 복원
        }
    }
}

int main() {

    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int num;
    cin >> num;
    vec = vector<int>(num, 0);
    

    vector<int> nums = { 1, 2, 3 };              // 사용할 숫자
    vector<int> counts(3, 0); //각 숫자(연산자)의 개수
    //vector<int> path;

    for (int i = 0; i < num; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> counts[i];
    }
    generate(nums, counts, path, num-1);


    cout << minn << " " << maxx;

    return 0;
}