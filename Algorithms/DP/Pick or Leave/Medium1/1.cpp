#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std; 

vector<int> nums; 
const int MAX{ 2501 }; 
int mem[MAX][MAX]; 

bool SubsetSum(int idx, int target) {
	if (target == 0)	return true; 
	if (target < 0) 	return false; 
	if (idx == (int)nums.size())	return false;

	auto& ret = mem[idx][target]; 
	if (ret != -1)	return ret;	
	if (SubsetSum(idx + 1, target))		return true; //leave
	
	return ret = SubsetSum(idx + 1, target - nums[idx]); //pick
}

int main() {
	memset(mem, -1, sizeof(mem));
	nums = { 3,12,4,12,5,2 }; 
	int sum = 9; 

	cout << boolalpha << SubsetSum(0, sum)<<'\n';
}
