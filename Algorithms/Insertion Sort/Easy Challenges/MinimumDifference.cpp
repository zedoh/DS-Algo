#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std; 

int MinSub(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    if (arr.empty())
        return -1;
    int mn = arr[1] - arr[0];
    for (int i = 1; i < (int)arr.size(); i++) {
        mn = min((arr[i] - arr[i - 1]), mn);

    }
    return mn;
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int target = MinSub(arr);
    for (int i = 1; i < (int)arr.size(); ++i) {
        vector<int>pairs;
        if (arr[i] - arr[i - 1] == target) {
            pairs.push_back(arr[i - 1]);
            pairs.push_back(arr[i]);
            result.push_back(pairs);
        }
    }

    return result;
}