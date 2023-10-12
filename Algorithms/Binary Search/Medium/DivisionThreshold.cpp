#include <vector>
#include <iostream>
using namespace std; 

int Divised(vector <int>& nums, int k) {
    int sum{ 0 };
    for (auto i : nums) {
        sum += (i + k - 1) / k;
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int start{ 1 }, end = *max_element(nums.begin(), nums.end());
    int answer{ 1 };
    int mid;
    while (start <= end) {
            mid = start + (end - start) / 2;
            if (Divised(nums, mid) <= threshold) {
                answer = mid, end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
    return answer;
}
