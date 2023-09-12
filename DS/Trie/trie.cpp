#include "trie.hpp"

trie::trie() : IsLeaf(0) {
    memset(child, 0, sizeof(child));
}

trie::~trie() {
    for (int i = 0; i < MAX_CHAR; ++i) {
        delete child[i];
    }
}

void trie::insert(std::string str, int idx) {
    if (idx == (int)str.size())
        IsLeaf = 1;
    else {
        int curr = str[idx] - 'a';
        if (child[curr] == 0)
            child[curr] = new trie();
        child[curr]->insert(str, idx + 1);
    }

}

bool trie::WordExist(std::string str, int idx) {
    if (idx == (int)str.size()) {
        return IsLeaf;
    }

    int curr = str[idx] - 'a';
    if (!child[curr])
        return false;

    return child[curr]->WordExist(str, idx + 1);
}

bool trie::PrefixExist(std::string str, int idx)
{
    if (idx == (int)str.size()) {
        return true;
    }

    int curr = str[idx] - 'a';
    if (!child[curr])
        return false;
    return child[curr]->PrefixExist(str, idx + 1);
}
