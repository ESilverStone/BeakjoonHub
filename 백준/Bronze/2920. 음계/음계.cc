#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count = 8;

	int before = 0;

	bool asc = false;
	bool des = false;
	bool mix = false;

	int num = 0;	

	cin >> before;

	for (int i= 0; i < count-1; i++) {

		cin >> num;

		if (num > before) {
			if (des) {
				mix = true;
				break;
			}
			else {
				asc = true;
			}
		}
		else {
			if (asc) {
				mix = true;
				break;
			}
			else {
				des = true;
			}
		}

		before = num;
	}

	if (mix) {
		cout << "mixed";
	}
	else if (asc && ! des) {
		cout << "ascending";
	}
	else {
		cout << "descending";
	}
	
	return 0;
}