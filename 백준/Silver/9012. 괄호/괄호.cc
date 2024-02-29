#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 0;
    cin >> N;

    for(int i=0; i<N; i++){

        string line;
        cin >> line;

        stack<char> st;

        bool result = true;

        for (char w : line)
        {
            if (w == '(') {
                st.push(w);
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
        }

        if (!st.empty()) result = false;

        if (result) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
}