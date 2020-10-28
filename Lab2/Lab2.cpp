// вариант 11
#include <iostream>
#include <cmath>
using namespace std;


int main() {
	float x, y;                             // x - coordinate; y - coordinate;
	cout << "Input x cord: "; cin >> x;
	cout << "Input y cord: "; cin >> y;
	if (y > x / 2 && pow((x - 2), 2) + pow(y, 2) <= 4) { // перевірка знаходження точки в заштрихованій площині
		cout << "The point is in the area." << endl;
	}
	else {
		cout << "The point isn`t in area." << endl;
	}
	return 0;
		
}