#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

class OsTrie {
private:
	map<string, OsTrie*> data;
	bool IsLeaf{ }; 
public:
	OsTrie() {}; 

	void Insert(vector<string> &list) {
		OsTrie* curr = this; 
		int sz = (int) data.size(); 
		if (list.empty()) return; 
		for (auto str : list) {
			if (!curr->data.count(str)) {
				curr->data[str] = new OsTrie(); 
			}
			curr = curr->data[str]; 
		}
		curr->IsLeaf = 1; 
	}


	bool FindPath(vector<string>& list) {
		OsTrie* curr = this;
		int sz = (int) data.size();
		if (list.empty()) {
			return false;
		}
		for (auto str : list) {
			if (!curr->data.count(str)) {
				return false; 
			}
			else {
				curr = curr->data[str]; 
			}
		}
		return true; 
	}
};

/*
int main() {
	OsTrie tree; 
	vector<string>paths{ "home", "dev" , "user" , "bin" }; 
	vector<string> test1{ "home" , "dev" , "user" , "programming" };
	vector<string> test2{ "home" , "dev" }; 
	tree.Insert(paths); 
	cout << boolalpha << tree.FindPath(test1) << '\n'; //0
	cout << boolalpha << tree.FindPath(test2) << '\n'; //1
}
*/