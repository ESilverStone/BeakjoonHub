#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX


using namespace std;


vector<int> memo;

int min_bag(int n) {
    // 딱코딱뎀
    if (n == 0) {
        return 0;
    } 
    // 불가능한 경우
    if (n < 0) {
        return INT_MAX;
    }

    // 이미 기억하고 있는 정보일 경우
    if (memo[n] != -1) {
        return memo[n];
    }

    // 3, 5 짜리 설탕 봉지
    int use_bag3 = min_bag(n - 3);
    int use_bag5 = min_bag(n - 5);

    // 불가능 한 경우 MAX 값이 넣어져 있어서 min 비교 시 걸리게 된다.
    // 만약 둘 다 불가능할 경우 min값이 MAX값이 나오는데 이는 출력 시 따로 처리
    // 가능한 경우 있을 경우 최소값을 넣어주고 회수를 1회 늘리고 memo배열에 저장해둔다.
    memo[n] = min(use_bag3, use_bag5) == INT_MAX ? INT_MAX : min(use_bag3, use_bag5) + 1;

    return memo[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // N 입력
    int N = 0;
    cin >> N;

    // 배열 -1로 초기화
    memo.resize(N + 1, -1);

    int result = min_bag(N);

    if (result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << result;
    }

}