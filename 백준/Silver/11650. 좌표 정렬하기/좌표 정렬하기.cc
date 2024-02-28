#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> arr;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << "\n";
    }

    return 0;
}