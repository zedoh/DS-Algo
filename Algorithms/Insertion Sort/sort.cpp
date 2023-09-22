#include <vector>
#include <iostream>
using namespace std; 


template <typename T>
void InsertionSort(vector<T>& a) {
	if (a.empty())
		return; 
	size_t j; 
	for (size_t i = 1; i < a.size(); i++) {
		T tmp = a[i]; 
		for (j = i; j > 0 && tmp < a[j - 1]; j--) {
			a[j] = a[j-1]; 
		}
			a[j] = tmp; 
	}
}
