#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	long sum = 0;
	int i = 0;
	for (char c : str) {
	
		sum += (c -'a' + 1) * pow(31, i);
		i++;
	}

	cout << sum;
}