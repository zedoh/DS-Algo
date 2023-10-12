#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int BinarySearch(vector<int>& nums, int target) {
    int sz = nums.size();
    int right = sz - 1;
    int left = 0;
    int mid{ 0 };

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        else if (target > nums[mid]) {
            left = mid + 1;
        }
        else if (target < nums[mid]) {
            right = mid - 1;
        }
    }
    return -1;
}
