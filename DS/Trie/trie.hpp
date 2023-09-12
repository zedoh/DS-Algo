#ifndef _TRIE_
#define _TRIE_
#include<iostream>

class trie {
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool IsLeaf;
public:
    trie();
    ~trie();
    void insert(std::string str, int idx = 0);
    bool WordExist(std::string str, int idx = 0);
    bool PrefixExist(std::string str, int idx = 0);

    void Insert(std::string str); //Iterative Version 
    bool word_exist(std::string str); //Iterative Version
};

#endif
