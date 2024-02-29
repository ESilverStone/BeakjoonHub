#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // N 입력
    int N;
    cin >> N;

    queue<int> que;

    // 1 - N의 숫자를 큐에 담는다
    for (int i = 1; i <= N; i++) {
        que.push(i);
    }

    // 임시 저장 넘버 > 최후의 숫자가 들어가게됨
    int temp = que.front();

    // 최상위 제거 후 다음의 상위 카드를 아래로 옮긴다.
    while (que.size() != 1) {
        // 상위 카드 제거
        que.pop();

        // 그 다음 상위 카드 저장
        temp = que.front();
        // 제거 후 삽입
        que.pop();
        que.push(temp);
    }
    cout << temp;

}