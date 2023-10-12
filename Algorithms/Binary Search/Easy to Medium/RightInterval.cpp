#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Unique Start --> map !!!!

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int sz = intervals.size();
    map <int, int> mapp;
    for (int i = 0; i < sz; ++i) {
        mapp.insert({ intervals[i][0] , i });
    }
    vector<int>res;
    for (int i = 0; i < sz; ++i) {
        int target = intervals[i][0];
        auto it = mapp.lower_bound(intervals[i][1]);
        if (it != mapp.end()) {
            res.push_back(it->second);
        }
        else
            res.push_back(-1);
    }
    return res;
}