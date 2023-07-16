#include<iostream>
#include<stack>

//Incomplete Implementation 
//Space : O(N) 
//Complexity : O(N)

int precedence(char op){
    if(op == '+' || op == '-') return 1 ; 
    if(op == '*' || op == '/') return 2 ; 
    return 0 ; //Invalid Operator
}

std::string ShuntingYard(std::string infix){
    std::stack<char>OP; 
    std::string output {""} ;
    infix += '-'  ; 
    int sz = infix.size() ; 
    OP.push('#') ; 

    for(int i = 0 ; i < sz ; ++i){
        if(isdigit(infix[i])){
            output+=infix[i] ; 
        }
        else{
        while(precedence(infix[i])<=precedence(OP.top())) // 1 step at the time  
            {
                output+=OP.top() ; 
                OP.pop() ; 
            }
            OP.push(infix[i]) ; 
        
        }
    }
    return output ; 
}

int main()
{
    std::string infix {"1*2-3+4"} ; 
    std::cout<<ShuntingYard(infix)<<'\n' ; 
}