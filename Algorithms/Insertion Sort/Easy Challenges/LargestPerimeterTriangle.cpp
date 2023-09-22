#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

int largestPerimeter(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < (int)nums.size() - 2; ++i) {
        if (nums[i] < nums[i + 1] + nums[i + 2]) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}