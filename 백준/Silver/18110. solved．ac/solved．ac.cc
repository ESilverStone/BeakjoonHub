#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits> // INT_MAX
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    vector<int> arr(N);

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    // 정렬
    sort(arr.begin(), arr.end());

    // 양쪽으로 15%씩 쳐내기
    double cutN = (double)N / 100 * 15;
    int cutRange = (int)round(cutN);

    double sum = 0;

    for (int i = cutRange; i < N - cutRange; i++) {
        sum += arr[i];
    }

    double avg = sum / (N - 2 * cutRange);
    int newAvg = (int)round(avg);

    cout << newAvg;


}