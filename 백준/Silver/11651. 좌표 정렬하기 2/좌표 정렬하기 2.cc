#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (get<1>(a) == get<1>(b)) {
        return get<0>(a) < get<0>(b);
    }
    else {
        return get<1>(a) < get<1>(b);
    }
}

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

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << "\n";
    }

    return 0;
}