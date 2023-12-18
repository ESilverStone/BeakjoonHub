#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;
	int y;

	cin >> x >> y;

	double z = static_cast<double>(x) / y;

	cout << fixed;
	cout.precision(12);
	cout << z << endl;

}