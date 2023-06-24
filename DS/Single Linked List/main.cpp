#include<iostream>
#include"List.hpp"

using namespace std ;
/*
    basic --> basic testing
    Easy --> Testing HW Easy functions
    Medium --> Testing HW medium functions
*/

void basic(){
    List list ; 
    cout<<"TEST 1 -> Basic Functions\n" ;
    cout<<"Insert Function\n" ;  
    cout<<"--------------------\n" ;  
    list.insert_end(11) ; 
    list.insert_end(12) ; 
    list.insert_end(13)  ; 
    list.insert_end(122)  ; 
    list.print() ; 
    cout<<endl ;
    cout<<"Get the Nth Element\n" ;  
    cout<<list.get_nth(2)->data<<endl  ; // 13 
    cout<<'\n'  ; 
    cout<<"current size of the list: "<<list.list_size()<<endl  ; 
    cout<<"Does the list is empty ?? "<<boolalpha<<list.empty()<<endl ; 

}

void Easy(){
    return ; 
}

void Medium(){
    return  ; 

}

int main()
{
    basic() ; 

    return 0;
}