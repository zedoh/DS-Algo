#include<iostream>
#include<stack>
using namespace std ; 


 
string  reverse_subword(string line){
    string result  ; 

    line+=' ' ; 
    stack<char> st ; 
    for(int i = 0 ; i  <(int)line.size() ; ++i){
        if(line[i] == ' '){
            while(!st.empty()){
                result += st.top() ; 
                st.pop() ; 
            }
            result +=' ' ; 
        }else{
            st.push(line[i]) ; 
        }
    }
    return result ; 
}

int main(){
   cout<< reverse_subword("abc d efg xy") ; 
    return 0 ;
}