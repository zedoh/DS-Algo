#include"STACK.hpp"
#include<iostream>
#include<stack>
using namespace std ; 

void msg(const string &line){
    cout<<"\n----------------------------------------------------------------\n" ; 
    cout<<line  ; 
    cout<<"\n----------------------------------------------------------------\n" ; 
}

void split(){
    cout<<"\n*******************************************************************\n" ; 
}


void basic(){
    Stack st(5); 
    st.push(1) ;
    st.push(23) ; 
    st.push(34) ; 
    st.push(34) ; 
    st.push(34) ; 
    st.push(55) ; 

    msg("Printing the stack") ; 
    st.display() ; 
    split() ; 


    msg("Deleting an Element from the stack !!") ; 
    st.pop() ; 
    st.display() ; 
    split() ; 

    cout<<st.peek() ; 
}


int main(){
    basic() ; 
    
    cout<<"\nNO RTE\n" ; 
}