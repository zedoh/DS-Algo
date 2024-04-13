#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <climits>

using namespace std ; 

const int MAX{2501}  ; 
int mem[MAX][MAX] ; 
vector<int> numlist; 

bool PickOrLeave(int idx, int target){
    if(target < 0) return false ;
    if(target == 0) return true ;
    if (idx == numlist.size()) return false ;
    auto &ret = mem[idx][target] ; 
    if(ret != -1){
        return ret ; 
    }
    if(PickOrLeave(idx+1 , target)){
        return ret = true ;
    }
    return ret = PickOrLeave(idx+1, target-numlist[idx]) ;
}

bool subset_sum(const vector<int> &values, int target){
    memset(mem,-1,sizeof(mem)) ; 
    numlist = values; 
    return PickOrLeave(0,target) ; 
}


void process_case(const vector<int> &values, int target, bool expected) {
	bool answer = subset_sum(values, target);

	if (answer != expected) {
		cout << "Wrong results: \t";
		for (int i = 0; i < (int) values.size(); ++i)
			cout << values[i] << " ";

		cout << "\tWith target: " << target<<"\n\n";
	}
}

int main() {
	int big = 1e8;
	process_case( { 3, 12, 4, 12, 5, 2 }, 9, true);
	process_case( { 3, 40, 4, 12, 5, 2 }, 30, false);
	process_case( { 10, 20, 30, 40, 50 }, 60, true);
	process_case( { 10, 20, 30, 40, 50 }, 100, true);
	process_case( { 10, 20, 30, 40, 50 }, 90, true);
	process_case( { 10, 20, 30, 40, 50 }, 70, true);
	process_case( { 10, 20, 30, 40, 50 }, 200, false);
	process_case( { 200 }, 300, false);
	process_case( { 200 }, 200, true);
	process_case( { big, big, big, big, big }, 60, false);
	process_case( { 1, 2, 3}, 6, true);

	cout<<"Done\n";
}