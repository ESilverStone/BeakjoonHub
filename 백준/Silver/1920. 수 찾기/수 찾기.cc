#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr1(N);

    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }

    sort(arr1.begin(), arr1.end());

    int M;
    cin >> M;

    vector<int> arr2(M);

    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }

    // 이진 탐색 구현
    for (int num : arr2) {
        if (binarySearch(arr1, num)) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}