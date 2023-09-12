#include "trie.hpp"
// Iterative Version // 

void trie::Insert(std::string str) {
    trie* curr = this;
    for (int i = 0; i < (int)str.size(); ++i) {
        int idx = str[i] - 'a';
        if (!curr->child[idx])
            curr->child[idx] = new trie();
        curr = curr->child[idx];
    }
    curr->IsLeaf = 1;
}

bool trie::word_exist(std::string str) {
    trie* curr = this;
    for (int i = 0; i < (int)str.size(); i++) {
        int idx = str[i] - 'a';
        if (!curr->child[idx]) {
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->IsLeaf;
}
