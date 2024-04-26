#include <iostream>
#include <vector>
#include <cstring>
using namespace std ; 

string str1, str2 ;
int mem[501][501];

int Edit(int idx1, int idx2)
{
    if (idx1 == (int)str1.size())
        return str2.size() - idx2;
    if (idx2 == (int)str2.size())
        return str1.size() - idx1;

    auto &ret = mem[idx1][idx2];
    if (~ret)
        return ret;

    // Choices

    if (str1[idx1] == str2[idx2])
        return ret = Edit(idx1 + 1, idx2 + 1);
    int Delete = 1 + Edit(idx1 + 1, idx2);
    int insert = 1 + Edit(idx1, idx2 + 1);
    int change = 1 + Edit(idx1 + 1, idx2 + 1);

    return ret = min(min(Delete, insert), change);
}

int minDistance(string word1, string word2)
{
    memset(mem, -1, sizeof(mem));
    str1 = word1;
    str2 = word2;
    return Edit(0, 0);
}