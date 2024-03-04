#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

// 정보 구조체
struct Info{
    int index;      // 정보의 순서
    int priority;   // 정보의 중요도
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int Test;
    cin >> Test;

    while (Test--) {
        
        // n : 정보의 개수
        // m : m번째 정보가 몇 번째로 나올지를 판단
        int n, m;
        cin >> n >> m;

        // 우선순위 큐
        queue<Info> que;

        // 돌리고 돌릴 큐
        priority_queue<int> pque;

        // n개의 정보 입력
        for (size_t i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            Info info;

            info.index = i;
            info.priority = num;
            

            que.push(info);
            pque.push(num);
        }

        while (!que.empty()) {
            // 1. 그냥 큐에서 info를 뽑아본다.
            Info fInfo = que.front();

            // 2. 우선 순위 큐에서 뽑은 우선 순위와 비교한다.
            if (fInfo.priority == pque.top()) {
                // 3-1. 맞다면 다 뽑기
                que.pop();
                pque.pop();

                // 4. 내가 찾고자하는 index가 맞으면 아웃
                if (fInfo.index == m) {
                    break;
                }
            }
            else {
                // 3-2. 다르다면 아직 차례가 아니므로 다시 넣기
                que.pop();
                que.push(fInfo);
            }

        }

        cout << (n - que.size()) << "\n";

    }


}