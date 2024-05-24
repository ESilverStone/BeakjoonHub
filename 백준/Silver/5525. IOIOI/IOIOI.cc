#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
string str;
vector<char> arr;
queue<char> que;

void clearQue(bool stayI) {
    while (!que.empty()) {
        que.pop();
    }

    if (stayI) {
        que.push('I');
    }
}

bool checkAns() {
    if (que.size() == n * 2 + 1) return true;
    else return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ans = 0;

    // input
    cin >> n >> m;
    cin >> str;

    //arr.resize(m);

    // 모든 경우의 수
    // 빈 배열에 O -> X 
    // 빈 배열에 I -> ok
    // O 다음에 I -> ok -> 큐 size 확인
    // I 다음에 O -> ok
    // O 다음에 O -> X -> 큐 clear
    // I 다음에 I -> X -> 큐 clear 후 I 삽입
    // 조건에 만족한 경우 이미 들어있는 I와 O -> 클리어 후 앞에 IO 만 제거
    for (char c : str) {
        // I
        if (c == 'I') {
            
            if (que.empty()) {
                que.push(c);
            }
            else if (que.back() == 'I') {
                clearQue(true);
            }
            else if (que.back() == 'O') {
                que.push(c);
                // 정답 확인
                if (checkAns()) {
                    // IO 제거
                    que.pop();
                    que.pop();
                    ans++;
                }
            }
        }
        // O
        else {
            if (que.empty()) {
                continue;
            }
            else if (que.back() == 'I') {
                que.push(c);
            }
            else if (que.back() == 'O') {
                clearQue(false);
            }
        }
    }

    cout << ans;

    
    return 0;
}