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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // 1. 숫자들을 입력 순으로 보관할 배열 1
    // 2. 배열 1을 오름차순으로 정렬한 배열 2
    // 3. 좌표값을 찍을 해시맵 3

    // 1. 입력
    vector<int> InputVec(N);

    for (int i = 0; i < N; i++) {
        cin >> InputVec[i];
    }

    // 2. 벡터 복사하기
    vector<int> SortVec(InputVec);
    sort(SortVec.begin(), SortVec.end());

    int count = 0;
    int beforeNum = SortVec[0];

    // 3.
    map<int, int> resultMap;
    for (int i = 0; i < N; i++) {

        // 이전 숫자와 다르다면 수정 후 count 값을 증가시킨다.
        if (beforeNum != SortVec[i]) {
            beforeNum = SortVec[i];
            count++;
        }
        
        resultMap[SortVec[i]] = count;
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        cout << resultMap[InputVec[i]] << ' ';
    }

    return 0;
}