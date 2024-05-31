#include <iostream>
#include <vector>
#include <queue>


using namespace std;

// 기록용 벡터
vector<vector<int>> memo;

int T;
int a, b;

// 함수 프로토타입(선언)
int moveLeft(int n);
int moveRight(int n);

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);

    // D : * 2
    // S : -1
    // L : 왼쪽으로 회전
    // R : 오른쪽으로 회전
    // 각각 memo에 1,2,3,4로 저장될 것
    while (!q.empty()) {


        int num = q.front();
        q.pop();

        if (num == end) break;

        // D
        {
            int nextIdx = (num * 2) % 10000;

            // 재방문을 막는다.
            if (memo[nextIdx].empty() && num != 0) {
                q.push(nextIdx);
                memo[nextIdx] = memo[num];
                memo[nextIdx].push_back(1);
            }
        }


        // S
        {
            int nextIdx = num == 0 ? 9999 : num - 1;

            if (memo[nextIdx].empty()) {
                q.push(nextIdx);
                memo[nextIdx] = memo[num];
                memo[nextIdx].push_back(2);
            }
        }

        // L
        {
            int nextIdx = moveLeft(num);
            if (memo[nextIdx].empty()) {
                q.push(nextIdx);
                memo[nextIdx] = memo[num];
                memo[nextIdx].push_back(3);
            }
        }

        // R
        {
            int nextIdx = moveRight(num);
            if (memo[nextIdx].empty()) {
                q.push(nextIdx);
                memo[nextIdx] = memo[num];
                memo[nextIdx].push_back(4);
            }
        }
    }
}

int moveLeft(int n) {
    // 첫 번째 숫자 저장
    int leftestNum = n / 1000;

    n = n * 10;
    n = n % 10000;
    n += leftestNum;

    return n;
}

int moveRight(int n) {
    // 네 번째 숫자 저장
    int rightestNum = n % 10;

    n = n / 10;
    n = n + 1000 * rightestNum;

    return n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    


    while (T--) {
        // 초기화 및 입력
        a = 0; b = 0;
        cin >> a >> b;

        memo.assign(10000, vector<int>());


        bfs(a, b);

        for (int n : memo[b]) {
            if (n == 1)         cout << "D";
            else if (n == 2)    cout << "S";
            else if (n == 3)    cout << "L";
            else                cout << "R";
        }

        cout << "\n";

    }


    return 0;
}