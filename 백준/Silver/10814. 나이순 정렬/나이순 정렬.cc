#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(const tuple<int, string, int>& a, const tuple<int, string, int>& b) {
    
    if (get<0>(a) == get<0>(b)) {

        return get<2>(a) < get<2>(b);
    }
    else {
        return get<0>(a) < get<0>(b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<tuple<int,string, int>> arr;
    
    for (int i = 0; i < N; i++) {
        int age;
        string name;

        cin >> age >> name;

        arr.push_back(make_tuple(age, name, i));
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << "\n";
    }

    return 0;
}