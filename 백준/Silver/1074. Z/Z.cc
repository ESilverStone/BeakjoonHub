#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <map>

using namespace std;

long long cnt = 0;
long long r, c;

// x,y 시작점
void divide(long long x, long long y, long long len) {
    
    // 답
    if (len == 1) {
        cout << cnt;
        exit(0);
    }

    long long leng = len / 2;
    long long jumpSize = leng * leng;

    // 1. 2사분면
    if (x <= c && c < x + leng && y <= r && r < y + leng) {
        divide(x, y, leng);
    }
    else if (x + leng <= c && c < x + len && y <= r && r < y + leng) {
        cnt += jumpSize;
        divide(x + leng, y, leng);
    }
    else if (x <= c && c < x + leng && y + leng <= r && r < y + len) {
        cnt += jumpSize * 2;
        divide(x, y + leng, leng);
    }

    else {
        cnt += jumpSize * 3;
        divide(x + leng, y + leng, leng);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N >> r >> c;

    // 1. N의 수가 뭐가 되었건간에 4등분을 하여 Z를 그린다.
    // 2. 그러나 아직 크기가 1인 블록이 아니다면 재귀로 4등분을 거듭한다.
    // 3. 최소 단위가 될때까지 재귀를 돌려 배열에 숫자를 채워나간다.

    // 한변의 길이
    long long len = pow(2, N);

    divide(0, 0, len);
    

    return 0;
}