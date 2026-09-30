#include <iostream>
#include <climits>
using namespace std;

int n, answer = INT_MAX;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Please write your code here.
    
    for (int i = 0; i < n; i++) {
        int temp =0;
        for (int j = 0; j < n; j++) {
            temp += abs(i-j)*A[j];
        }
        answer = min(answer, temp);
    }
    cout << answer;
    return 0;
}