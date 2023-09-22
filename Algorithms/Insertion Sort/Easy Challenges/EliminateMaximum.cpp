#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int sz = dist.size();
    vector<int>timing(sz);

    for (int i = 0; i < (int)dist.size(); ++i) {
        if (dist[i] % speed[i] == 0)
            timing[i] = dist[i] / speed[i];
        else
            timing[i] = dist[i] / speed[i] + 1;
    }

    int count{ 0 };
    sort(timing.begin(), timing.end());
    for (int i = 0; i < (int)timing.size() && i < timing[i]; ++i) {
        ++count;
    }
    return count;
}