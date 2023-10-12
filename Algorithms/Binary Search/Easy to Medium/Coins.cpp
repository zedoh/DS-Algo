#include <vector>
#include <iostream>
using namespace std; 

bool possible(int n, long long  k) {
    return n >= (k * (k + 1)) / 2;
}
int arrangeCoins(int n) {
    int left = 0, right = n, answer = 0, mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (possible(n, mid)) {
            left = mid + 1;
            answer = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}