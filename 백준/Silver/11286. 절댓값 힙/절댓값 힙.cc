#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pos_que;     // 양수 큐
priority_queue<int, vector<int>, less<int>> neg_que;        // 음수 큐


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n--) {
        int cmd;

        cin >> cmd;

        // 절댓값이 가장 작은 값을 출력하고 제거
        // 비어 있는 경우 절댓값이 가장 작은 값을 출력
        // 절댓값이 가장 작은 값이 여러개일 때 가장 작은 수 출력
        if (cmd == 0) {
            int pos = 0;
            int neg = 0;

            if (pos_que.empty() && neg_que.empty()) {
                cout << 0 << endl;
                continue;
            }

            if (!pos_que.empty()) pos = pos_que.top();
            if (!neg_que.empty()) neg = neg_que.top();

            if (abs(pos) < abs(neg)) {

                if (pos == 0) {
                    neg_que.pop();
                    cout << neg << endl;
                }
                else {
                    pos_que.pop();
                    cout << pos << endl;
                }
            }
            else {
                if (neg == 0) {
                    pos_que.pop();
                    cout << pos << endl;
                } else {
                    neg_que.pop();
                    cout << neg << endl;
                }
            }

        }

        // 값을 추가
        else {
            if (cmd > 0) {
                pos_que.push(cmd);
            }
            else {
                neg_que.push(cmd);
            }
        }
    }
    

    return 0;
}