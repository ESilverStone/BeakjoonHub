#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

vector<vector<int>> arr;

int bCnt = 0;
int wCnt = 0;

// s1,e1 : 가로 기준 시작과 끝
// s2,e2 : 세로 기준 시작과 끝
void examine(int s1, int e1, int s2, int e2) {

    // 크기가 1일 때
    if (s1 == e1) {
        if (arr[s1][s2] == 1) bCnt++;
        else wCnt++;

        return;
    }

    bool isAllBlue = true;
    bool isAllWhite = true;

    // 다 파랑파랑인지 검사
    for (int i = s1; i <= e1; i++) {
        for (int j = s2; j <= e2; j++)
        {
            // 하나라도 흰색이라면
            if (arr[i][j] == 0) {
                isAllBlue = false;
                
            }
            // 하나라도 파랑이라면
            if (arr[i][j] == 1) {
                isAllWhite = false;
               
            }
        }
    }
    

    if (isAllBlue) {
        bCnt++;
    }
    else if (isAllWhite) {
        wCnt++;
    }
    else {
        int length = (e1 - s1 + 1) / 2;

        // 4등분의 사각형
        examine(s1, s1 + length - 1, s2, s2 + length - 1);
        examine(s1, s1 + length - 1, s2 + length, e2);
        examine(s1 + length, e1, s2, s2 + length - 1);
        examine(s1 + length, e1, s2 + length, e2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr.resize(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i + 1][j + 1];
        }
    }

    examine(1, n, 1, n);

    cout << wCnt << "\n";
    cout << bCnt << "\n";


    return 0;
}