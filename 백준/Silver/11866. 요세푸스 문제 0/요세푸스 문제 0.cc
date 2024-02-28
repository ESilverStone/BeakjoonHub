#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 요세푸스 문제 해결을 위한 큐 생성
    queue<int> que;

    // n: 사람 수, k: 제거 규칙
    int n, k;
    cin >> n >> k;

    // 일단 다 넣기
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }

    cout << "<";

    // k-1개는 넣었다가 빼고 k번째는 제거
    while (que.size() != 1) {
        for (int i = 1; i < k; i++) {
            int frontNum = que.front();
            que.pop();
            que.push(frontNum);
        }
        int popNum = que.front();
        que.pop();
        
        cout << popNum << ", ";
    }

    int popNum = que.front();
    que.pop();

    cout << popNum << ">";
}