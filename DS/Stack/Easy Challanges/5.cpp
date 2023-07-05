#include<iostream>
#include<stack>

using namespace std ; 


string removeDuplicates(string s){
    stack<char> st ; 
    int sz = s.size() ; 

    for(int i = sz ; i>=0 ; i--){
        char ch  = s[i]  ;
        if(st.empty() || st.top()!= ch){
            st.push(ch) ; 
        }else{
            st.pop() ; 
        }
    }
    string answer = "";
    while (!st.empty()){
        answer += st.top();
        st.pop() ; 
    }
    return answer;
}

int main(){
    cout<<removeDuplicates("azxxzy")<<'\n' ;  //ay
}