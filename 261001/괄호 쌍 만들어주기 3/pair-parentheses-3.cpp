#include <iostream>
#include <string>

using namespace std;

string A;
int answer;

int main() {
    cin >> A;
    int len = A.length();

    // Please write your code here.
    for(int i=0;i<len;i++){
        if(A[i] == '('){
            for(int j=i+1; j<len; j++){
                if(A[j] == ')'){
                     answer++;
                    //  cout << i << ' ' << j << '\n';
                }
            }
        }
    }
    cout << answer;

    return 0;
}