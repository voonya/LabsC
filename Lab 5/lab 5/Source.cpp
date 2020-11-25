#include <iostream>
#include <iomanip>
using namespace std;

// вариант 7

int main() {
	for (int i = 1; i <= 1000; i++) {
		int x = i;
		int reverseX = 0, modX;
		while (x > 0) {
			modX = x % 10;
			x = x / 10;
			reverseX = reverseX * 10 + modX;
		}
		if (reverseX == i) {
			cout << setw(5) << i << endl;
		}
	}
	return 0;
}