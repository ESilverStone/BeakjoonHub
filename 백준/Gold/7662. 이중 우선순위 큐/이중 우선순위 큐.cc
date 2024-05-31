#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, int> cnt;


void clearTop() {
    while (!maxHeap.empty() && cnt[maxHeap.top()] == 0) { maxHeap.pop(); }
    while (!minHeap.empty() && cnt[minHeap.top()] == 0) { minHeap.pop(); }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    // 테스트 수
    while (T--) {
        int N;
        cin >> N;

        //int dCnt = 0;

        // 초기화
        while (!maxHeap.empty()) { maxHeap.pop(); }
        while (!minHeap.empty()) { minHeap.pop(); }
        cnt.clear();

        // 입력 수
        while (N--) {
            // 커멘드 입력
            char c;
            int num;
            cin >> c >> num;

            if (c == 'I') {
                maxHeap.push(num);
                minHeap.push(num);
                cnt[num]++;
            }
            else {
                if (num == 1) 
                {
                    clearTop();
                    if (maxHeap.empty()) continue;

                    cnt[maxHeap.top()]--;
                    maxHeap.pop();
                }
                if (num == -1) {
                    clearTop();
                    if (maxHeap.empty()) continue;

                    cnt[minHeap.top()]--;
                    minHeap.pop();
                }
                
                
            }
        }

        clearTop();
        // 모든 연산을 처리한 후 Q에 남아 있는 값 중 최댓값과 최솟값을 출력합니다.
        if (minHeap.empty() || maxHeap.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << maxHeap.top() << " " << minHeap.top() << "\n";
        }
    }

    return 0;
}