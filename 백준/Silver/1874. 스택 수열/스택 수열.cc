#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> st;
    vector<int> ans(n);
    vector<string> memo;

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    int index = 0;
    bool isPos = true;

    for (int i = 1; i <= n; i++) {
        st.push(i);
        memo.push_back("+");

        while (st.top() >= ans[index]) {
            // 답이 없는 경우
            if (st.top() > ans[index]) {
                cout << "NO";
                return 0;
            }
            else if(st.top() == ans[index]){
                st.pop();
                memo.push_back("-");
                index++;

                if (st.empty()) break;
            }
        }
    }

    for (int i = 0; i < memo.size(); i++) {
        cout << memo[i] << "\n";
    }
    return 0;
}