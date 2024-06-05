#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r,c,t;
vector<vector<int>> arr;
vector<vector<int>> next_arr;

// 검사 방향 맟 바람 시계 방향으로도 사용
// 바람 시계 하 우 상 좌
int w_rc_dirX[4] = { 1,0,-1,0 };
int w_rc_dirY[4] = { 0,1,0,-1 };

// 바람 반시계 상 우 하 좌
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,1,0,-1 };

int divide(int x) {
    return x / 5;
}

void wind_move_reverse_clockwise(int sx, int sy) {
    int cx = sx - 2;
    int cy = sy;

    // 바람 방향 인덱스
    int w_idx = 0;

    // sx, sy로 부터 시계방향의 바람을 거슬러 가면서 처리
    while (arr[cx][cy] != -1) {

        int nx = cx + dirX[w_idx];
        int ny = cy + dirY[w_idx];

        // 범위를 넘어갈 때마다 바람의 방향을 전환해준다.
        if (nx < 0 || ny < 0 || nx >= sx || ny >= c) {
            w_idx++;
            continue;
        }

        if (arr[nx][ny] == -1) {
            arr[cx][cy] = 0;
        }
        else {
            // 다음 위치의 먼지 수를 청정기 쪽으로 땡겨오는 느낌
            arr[cx][cy] = arr[nx][ny];
        }

        cx = nx;
        cy = ny;
    }
}

void wind_move_clockwise(int sx, int sy) {
    int cx = sx + 1;
    int cy = sy;

    // 바람 방향 인덱스
    int w_idx = 0;

    // sx, sy로 부터 시계방향의 바람을 거슬러 가면서 처리
    while (arr[cx][cy] != -1) {
        
        int nx = cx + w_rc_dirX[w_idx];
        int ny = cy + w_rc_dirY[w_idx];

        // 범위를 넘어갈 때마다 바람의 방향을 전환해준다.
        if (nx < sx || ny < 0 || nx >= r || ny >= c) {
            w_idx++;
            continue;
        }

        if (arr[nx][ny] == -1) {
            arr[cx][cy] = 0;
        }
        else {
            // 다음 위치의 먼지 수를 청정기 쪽으로 땡겨오는 느낌
            arr[cx][cy] = arr[nx][ny];
        }


        cx = nx;
        cy = ny;
    }
}

void spread_dust() {

    // 모든 지역 검사
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            int count = 0;

            // 확산될 먼지량
            int dn = divide(arr[i][j]);

            for (int d = 0; d < 4; d++) {
                int nx = i + dirX[d];
                int ny = j + dirY[d];

                // 막힌 지역
                if (nx < 0 || ny < 0 || nx >= r || ny >= c ) continue;

                // 공기청정기 지역
                if (arr[nx][ny] == -1) continue;

                count++;

                // 다음 배열에 적용될 먼지의 양 저장
                next_arr[nx][ny] += dn;
            }

            // 빠져나간 먼지의 양만큼 감소
            next_arr[i][j] -= dn * count;
        }
    }

    // 모든 지역의 변화량을 검사했다면 해당 수치를 적용
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] += next_arr[i][j];
        }
    }
}

void clear_arr() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            next_arr[i][j] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> t;
    
    arr.resize(r, vector<int>(c, 0));
    next_arr.resize(r, vector<int>(c, 0));

    int refresher_x = 0, refresher_y = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == -1) {
                refresher_x = i;
                refresher_y = j;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        // 초기화
        clear_arr();

        // 먼지 확산
        spread_dust();

        // 바람에 의한 먼지 이동
        wind_move_clockwise(refresher_x, refresher_y);
        wind_move_reverse_clockwise(refresher_x, refresher_y);
    }

    // 청정기에 -1 값이 들어가 있는 것 고려
    int ans = 2;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}