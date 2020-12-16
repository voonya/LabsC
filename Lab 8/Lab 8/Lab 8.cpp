#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>

using namespace std;



int** input_matrix(int, int);
void output_matrix(int**, int, int);
float* count_average(int**,int, int);
void output_arr(float[], int);
float count_Y(float[], float[], int);

int main() {
	srand(time(NULL));

	int m, n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;

	int** A = input_matrix(m,n);
	int** B = input_matrix(m, n);
	

	
	cout << "Matrix A: " << endl;
	output_matrix(A, m, n);

	
	cout << "Matrix B: " << endl;
	output_matrix(B, m, n);

	float* b_avg = count_average(B, m, n);
	float* a_avg = count_average(A, m, n);
	
	cout << "Average A: ";
	output_arr(a_avg, n);
	cout << endl;
	cout << "Average B: ";
	output_arr(b_avg, n);
	cout << endl;

	float sum_Y = count_Y(a_avg, b_avg, n);
	printf("Y is: %8.2f", sum_Y);

	return 0;
}

int** input_matrix(int m, int n) {   // генерація матриці розміру m на n
	int** matrix_gen = new int* [m];	// створення масиву покажчиків
	for (int j = 0; j < m; j++) {   //додавання до матриці пустих рядків
		matrix_gen[j] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix_gen[i][j] = (rand() % 21) - 10; // заповнення рядків і стовпчиків випадковими числами
		}
	}
	return matrix_gen;
}
void output_matrix(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << arr[i][j];  // виведення елементів матриці
		}
		cout << endl;
	}
	cout << endl;
}
float* count_average(int** matrix, int m, int n) {
	float* arr = new float[n];
	for (int j = 0; j < n; j++) {
		int count_el = 0;
		float sum = 0;
		float average = 0;
		for (int i = 0; i < m; i++) {
			sum += matrix[i][j];
			count_el++;
		}
		average = sum / count_el;
		arr[j] = average;	
	}
	return arr;
}
void output_arr(float arr[], int size_arr) {   
	for (int i = 0; i < size_arr; i++) { 
		printf("%8.2f", arr[i]);
	}

}
float count_Y(float arr_a[], float arr_b[], int size_arr) {
	float sum = 0;
	for (int i = 0; i < size_arr; i++) {
		sum += fabs(arr_a[i] - arr_b[i]);
	}
	return sum;
}