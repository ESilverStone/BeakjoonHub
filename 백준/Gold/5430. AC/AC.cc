#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int T;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        string st;
        cin >> st;

        // 명령어
        // 0 : 뒤집기
        // 1 : 삭제하기
        vector<int> cmd;

        for (char c : st) {
            if (c == 'R')   cmd.push_back(0);
            else            cmd.push_back(1);
        }

        // 숫자 보관 DEQUE를 활용해서 보관
        int n;
        cin >> n;
        deque<int> arr;

        string num_st;
        cin >> num_st;

        int num = 0;

        for (char c : num_st) {
            if (c >= '0' && c <= '9') {
                num *= 10;
                num += c - '0';
            }
            else {
                if (num == 0) continue;
                else {
                    arr.push_back(num);
                    num = 0;    // 초기화
                }
            }
        }

        bool isError = false;
        bool readRight = true;

        // 커멘드 처리
        for (int c : cmd) {
            // 뒤집기
            // Deque 이므로 읽는 방향만 바꿔주면 된다.
            if (c == 0) {
                readRight = !readRight;
            }
            // 삭제
            else {
                if (arr.empty()) isError = true;
                else {
                    if (readRight)  arr.pop_front();
                    else            arr.pop_back();

                }

            }
        }

        // 출력
        if (isError) cout << "error" << endl;
        else {
            cout << "[";

            if (readRight) {
                while (arr.size() > 1) {
                    cout << arr.front() << ",";
                    arr.pop_front();
                }
            }
            else {
                while (arr.size() > 1) {
                    cout << arr.back() << ",";
                    arr.pop_back();
                }
            }
            if (arr.size() == 1) {
                cout << arr.front() << "]" << endl;
            }
            else {
                cout << "]" << endl;
            }
        }
    }
    

    return 0;
}