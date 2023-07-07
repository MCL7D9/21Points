#include <iostream>
#include <cstdlib>
void print_arr(int* array){
	int size = sizeof(array / 8);
	for (int i = 0; i < size; i++) {
		cout << "[" << array[i] << "]";
		system("pause");
		return 0;
	}
}