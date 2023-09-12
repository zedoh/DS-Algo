#include <iostream>
#include <vector>
#include <cassert>


class TRIE{
private: 
	static const int MAX_SIZE{ 26 }; 
	bool IsLeaf{ }; 
	TRIE* child[MAX_SIZE]; 

public:
	TRIE() {
		memset(child, 0, sizeof(child)); 
	}

	~TRIE() {
		for (int i = 0; i < MAX_SIZE; ++i) {
			delete child[i]; 
		}
	}

	void insert(std::string &str) {
		TRIE* curr = this; 
		reverse(str.begin(), str.end()); 
		for (int i = 0; i < str.size(); ++i) {
			int ch = str[i] - 'a'; 
			if (!curr->child[ch])
				curr -> child[ch] = new TRIE(); 
			curr = curr->child[ch]; 
		}
		curr->IsLeaf = 1; 
	}


	bool suffix_exist(std::string str) {
		reverse(str.begin(), str.end()); 
		TRIE* curr = this; 
		for (int i = 0; i < (int)str.size(); ++i) {
			int ch = str[i] - 'a'; 
			if (!curr->child[ch])
				return false;
			curr = curr->child[ch]; 
		}
		return true; 
	}
	
};


