#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


void input_arr(int*,int);
void output_arr(int[], int);
int find_smallest(int[], int[], int, int);




int main()
{
	srand(time(NULL));
	int z,						// кількість елементів масиву
		smallest_number;		//найменше число, що не входить до масиву К
	 
	cout << "Input size of array: ";
	cin >> z;
	cout << endl;

	int* M = new int[z];
	int* K = new int[z];


	input_arr(M, z);        
	input_arr(K, z);


	cout << "Array M: ";
	output_arr(M, z);

	cout << "Array Z: ";
	output_arr(K, z);

	smallest_number = find_smallest(M, K, z, z); //знаходження найменшого елемента множини M, якого немає у множині K
	cout << "The smallest number, that is not in array K: " << smallest_number << endl;

	delete M;
	delete K;
	return 0;
}

void input_arr(int *arr,int count_element) {
	for (int i = 0; i < count_element; i++) {		
		*arr = rand() % 51;
		arr++;
	}

}
void output_arr(int arr[], int count_element) {
	for (int i = 0; i < count_element; i++) {
		cout << setw(6) << arr[i];
	}
	cout << "\n\n";
}

int find_smallest(int arr1[],int arr2[], int size_arr1, int size_arr2) {
	int smallest_n = 100;
	for (int i = 0; i < size_arr1; i++) {
		bool n_in_arr2 = false;                       // флаг чи присутній елемент arr1[i] у arr2
		for (int k = 0; k < size_arr2; k++) {
			if (arr1[i] == arr2[k]) {
				n_in_arr2 = true;
			}
		}
		if (n_in_arr2 == false && arr1[i] < smallest_n) {
			smallest_n = arr1[i];
		}
	}
	return smallest_n;
}