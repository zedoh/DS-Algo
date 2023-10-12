#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


template <typename T>
void SortV2(vector<T>& arr) {
	if (arr.empty() || arr.size() == 1)
		return; 
	
	for (int i = 1 ; i < (int)arr.size(); ++i) {
		int j = i; 
		while (arr[j] > arr[j - 1] && j > 0) {
			swap(arr[j], arr[j - 1]); 
			--j;
		}
	}
}

int main() {
	vector<int> arr{ 123,22,41,34,2,5 }; 
	SortV2(arr); 
	for (auto i : arr) {
		cout << i << '\t'; 
	}
}