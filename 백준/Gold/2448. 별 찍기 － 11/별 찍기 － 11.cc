#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> arr;


// ex 12 , 24
void star(int sx, int ex, int sy, int ey) {

    // end 조건
    if (ex - sx == 2) {
        arr[sx][sy + 2] = 1;
        arr[sx + 1][sy + 1] = 1;
        arr[sx + 1][sy + 3] = 1;
        arr[sx + 2][sy + 0] = 1;
        arr[sx + 2][sy + 1] = 1;
        arr[sx + 2][sy + 2] = 1;
        arr[sx + 2][sy + 3] = 1;
        arr[sx + 2][sy + 4] = 1;

        return;
    }

    int lx = ex - sx + 1;
    int ly = ey - sy + 1;

    // 상단 중앙
    star(sx , sx + lx / 2 - 1, sy + ly / 4, sy + ly / 4 + ly / 2 - 1);

    // 하단 좌측
    star(sx + lx / 2, ex,  sy , sy + ly / 2 - 1);

    // 하단 좌측
    star(sx + lx / 2, ex,  sy + ly / 2, ey);

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    // 입력 받은 n을 k로 나타낸다.
    int m = n / 3;
    int k = log2(m);

    // 계산 편의상 1을 더해준다.
    arr.resize(n + 1, vector<int>(2 * n + 1));
    
    star(1, n, 1, 2 * n);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < 2 * n + 1; j++) {
            if (arr[i][j] == 1) {
                cout << "*";
            }
            else cout << " ";
        }
        cout << "\n";
    }
    

    return 0;
}