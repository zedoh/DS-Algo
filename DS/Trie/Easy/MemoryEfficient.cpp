#include<iostream>
#include<map>
#include<vector>
#include <utility>
using namespace std;


class Trie {
private: 
	map<int,Trie*>data; 
	bool IsLeaf{ };

public:
	Trie() {};
	~Trie() {
		data.clear(); 
	}

	void insert(string& word) {
		Trie* curr = this;  
		for (int i = 0; i < (int)word.size(); ++i) {
			int idx = word[i] - 'a'; 
			if (!curr->data.count(idx)){
				curr->data[idx] = new Trie() ; 
			}
			curr = curr->data[idx];
		}
		curr->IsLeaf = 1; 
	}

	bool WordExist(string str) {
		if (str.empty())
		{
			cout << "\nPlease Enter a valid string!\n"; 
			return false; 
		}
		Trie* curr = this; 
		for (int i = 0; i < str.size(); ++i) {
			int idx = str[i] - 'a'; 
			if (!curr->data.count(idx)) {
				return false; 
			}	
			curr = curr->data[idx]; 
		}
		return curr->IsLeaf;
		
	}
	
};


// TEST //
/*
int  main() {
	Trie t; 
	vector<string>WORDS{
		"zeyad" , "name" , "youssef" , "hesham" , "noha" , "radwa" , "mohamed" , "mahmoud" , "mou"
	}; 
	for (auto word : WORDS) {
		t.insert(word); 
	}
	cout << boolalpha << t.WordExist("zeyad")<<'\n';
	cout << boolalpha << t.WordExist("zoo") << '\n';
	cout << boolalpha << t.WordExist("noha") << '\n'; 
	cout << boolalpha << t.WordExist("radwan") << '\n'; 

}
*/