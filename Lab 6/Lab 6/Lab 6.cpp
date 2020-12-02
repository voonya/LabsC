#include <iostream>
using namespace std;

double gX(double);


int main() {
	float y;
	cout << "Input y: "; cin >> y;
	float main_result = (1.7 * gX(0.25) + 2 * gX(1 + y)) / (6 - gX(pow(y, 2) - 1));
	cout << "Output: " << main_result;

	return 0;
}

double gX(double x) {
	if (x != 0) {
		double xNum_1 = x, xNum_0;  // xNum_1 current member of numerator , xNum_0 - previous member		
		double xDiv_1 = 1, xDiv_0;	// xDiv_1 current member of divider (the first member is always equals to 1 ), xDiv_0 - previous member
		double numerator = xNum_1, divider = xDiv_1;
		double result;
		for (int i = 1; i <= 10; i++) {
			// calculating numerator
			xNum_0 = xNum_1;
			xNum_1 = xNum_0 * pow(x, 2) / ((2 * i) * (2 * i + 1));  // recurrent formula of sum of numerator
			numerator += xNum_1;

			// calculating divider
			xDiv_0 = xDiv_1;
			xDiv_1 = xDiv_0 * pow(x, 3) / ((3 * i) * (3 * i - 1) * (3 * i - 2)); // recurrent formula of sum of divider
			divider += xDiv_1;
		}
		result = numerator / divider;
		return result;
	}
	cout << "The argument of g(x) function cant be 0" << endl;
	exit(1);
}