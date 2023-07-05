#include<iostream>
#include<stack>

using namespace std ; 

char is_open_match(char ch){
    if(ch == '}') return '{'; 
    if(ch == ')') return '(' ; 
    if(ch == ']') return '[' ; 

    return '/0' ; //Invalid character 
}

bool isValid(const string &str){
    stack <char> st ; 
    
    for(int i = 0 ; i < (int)str.size() ;++i){
        char ch = str[i] ; 
        if(ch == '('||ch=='{'||ch=='[') st.push(ch) ; 
        else if(ch ==')'||ch=='}'||ch==']'){
            if(st.empty()||st.top()!=is_open_match(ch)){
                return false  ;
            }
            st.pop() ; 
        }
    }
    return true ; 
}