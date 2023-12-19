#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;

		string text;
		//getline(cin, text);
		cin >> text;

		for (int j = 0; j < text.length(); j++) {

			for (int i = 0; i < n; i++) {
				cout << text[j];
			}

		}
		cout << endl;
	}
	
	return 0;
}