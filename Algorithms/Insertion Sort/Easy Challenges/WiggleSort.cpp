#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

void WiggleSort(vector<int>& a) {
	sort(a.begin(), a.end()); 
	for (int i = 1; i < (int)a.size()-1; i+=2) {
		swap(a[i], a[i + 1]); 
	}
}
