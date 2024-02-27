#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, v;
	cin >> a >> b >> v;

	int length = v - a;
	int diff = a - b;
	
	double result = ceil(static_cast<double>(length) / diff) + 1;

	cout << (int)result;
}