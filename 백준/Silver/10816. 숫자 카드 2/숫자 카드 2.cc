#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<int, int> mapN;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        mapN[num]++;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        cout << mapN[num] << " ";
    }
}