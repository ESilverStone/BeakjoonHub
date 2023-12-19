#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test = 0;

	cin >> test;

	for (int t = 0; t < test; t++) {

		string ans;

		cin >> ans;

		int point = 0;
		int series = 1;

		for (int i = 0; i < ans.length(); i++) {
			
			if (ans[i] == 'O') {
				point += series;

				series++;
			}
			else {
				series = 1;
			}
		}

		cout << point << endl;
	}
	
	return 0;
}