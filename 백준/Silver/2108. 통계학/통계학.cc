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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> frequency(8001);

    // 1. 산술 평균
    double sum = 0;

    // 4. 범위
    int min = 4001;
    int max = -4001;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        arr[i] = num;

        sum += num;

        // 3. 최빈값
        frequency[num + 4000]++;

        if (min > num) min = num;
        if (max < num) max = num;
    }

    // 2. 중앙값
    sort(arr.begin(), arr.end());

    if (sum / n < 0 && sum / n > -1) {
        sum = abs(round(sum / n));
    }
    sum = round(sum / n);

    // 1.
    cout << sum <<"\n";
    // 2.
    
    cout << arr[(n - 1) / 2] << "\n";
    // 3.
    int fMax = 0;
    vector<int> indexArr;

    for (int i = 0; i < frequency.size(); i++) {
        if (fMax < frequency[i]) {
            fMax = frequency[i];            
        }
    }

    for (int i = 0; i < frequency.size(); i++) {
        if (fMax == frequency[i]) {            
            indexArr.push_back(i - 4000);
        }
    }

    sort(indexArr.begin(), indexArr.end());

    if (indexArr.size() >= 2) {
        cout << indexArr[1] << "\n";
    }
    else {
        cout << indexArr[0] << "\n";
    }


    // 4.
    cout << max - min;




}