#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	string str;


	cin >> n;
	cin >> str;

	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		int num = str[i] - '0';
		sum += num;
	}

	cout << sum;
	
	return 0;
}