#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int triangleNumber(vector<int>& nums) {
	int count = 0, n = nums.size();
	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 2; i++) {
		int k = i + 2;	
		for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
			int first_idx = nums.size();
			auto iter = lower_bound(nums.begin() + k, nums.end(), nums[i] + nums[j]);
			if (iter != nums.end())
				first_idx = iter - nums.begin();
			count += first_idx - j - 1;
		}
	}
	return count;
}
