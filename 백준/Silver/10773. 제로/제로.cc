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

    int N;
    cin >> N;
    
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num != 0) {
            st.push(num);
        }
        else {
            st.pop();
        }
        
    }

    int sum = 0;

    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum;
}