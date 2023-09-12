#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class trie {
private:
    static const int CHAR{ 26 };
    trie* child[CHAR];
    bool is_leaf{ };
public:
    trie() {
        memset(child, 0, sizeof(child));
    }
    void insert(string str, int idx = 0) {
        if (idx == (int)str.size()) {
            is_leaf = 1;
        }
        else {
            int curr = str[idx] - 'a';
            if (!child[curr])
                child[curr] = new trie();
            child[curr]->insert(str, idx + 1);
        }
    }
    string PrefixWord(string& str) {
        trie* curr = this;
        for (int i = 0; i < (int)str.size(); ++i) {
            int idx = str[i] - 'a';
            if (!curr->child[idx])
                break;
            if (curr->child[idx]->is_leaf) {
                return str.substr(0, i + 1);
            }
            curr = curr->child[idx];
        }
        return str;
    }
};
// Holds the values of the sentence without spaces for better processing...
vector<string>Words(string& sentence) {
    vector<string>result;
    istringstream iss(sentence);
    string word;
    while (iss >> word) {
        result.push_back(word);
    }
    return result;
}


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie t;
        string result = "";
        vector<string>w = Words(sentence);
        for (auto str : dictionary) {
            t.insert(str);
        }
        for (int i = 0; i < (int)w.size(); ++i) {
            if (i) {
                result += " ";
            }
            result += t.PrefixWord(w[i]);

        }

        for (auto x : w) {
            cout << x << '\n';
        }

        return result;
    }
};