#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;

	cin >> a >> b >> c;

	int mul = a * b * c;
	
	string str = to_string(mul);

	int nums[10] = {0};

	for (int i = 0; i < str.length(); i++) {
		nums[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {

		cout << nums[i]<<endl;
	}
	
	return 0;
}