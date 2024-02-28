#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long M = 1234567891;

	int n;
	cin >> n;
	

	string str;
	cin >> str;

	long long sum = 0;
	long long power = 1;
	for (char c : str) {
	
		sum += ((c -'a' + 1) * power) % M;
		power = (power * 31) % M;
	}

	cout << sum % M;
}