#include<iostream>
#include"DList.hpp"
using namespace std ; 

void msg(const string &line){
    cout<<"\n----------------------------------------------------\n" ; 
    cout<<line<<'\n' ; 
    cout<<"*******************************************************\n" ; 
}

void basic1(){
    DList list ;

    msg("INSERT END");
    list.insert_end(11) ; 
    list.insert_end(2) ;  
    list.insert_end(3) ;  
    list.insert_end(4) ;  
    list.insert_end(5) ;  

    msg("INSERT FRONT") ; 
    list.insert_front(10000) ;
    list.insert_front(20000) ;
    list.insert_front(30000) ;
    list.insert_front(40000) ;

    msg("INSERT SORTED") ; 
    list.insert_sorted(10) ; 
    list.insert_sorted(15) ; 
    list.insert_sorted(1) ; 
    list.insert_sorted(22312) ; 
    list.insert_sorted(500) ; 
    list.print() ; 

    msg("Deleting the front of 3 elements") ; 
    list.delete_front() ; 
    list.delete_front() ; 
    list.delete_front() ; 
    list.print() ; 


    msg("Deleting the last 2 elements in the list") ; 
    list.delete_end() ; 
    list.delete_end() ; 
    list.print() ; 
}

void basic2(){
    DList list ; 
    // list.insert_end(1) ; 
    // list.insert_end(2) ; 
    // list.insert_end(3) ; 
    // list.insert_end(4) ; 
    // list.insert_end(5) ; 
    // list.insert_end(6) ; 
    // msg("Normal List Printing") ; 
    // list.print() ; 

    // msg("Deleting the node with the value 1 ") ; 
    // list.delete_node_with_key(1) ; 
    // list.print() ; 

    // list.insert_front(1) ; 
    // list.insert_front(1) ; 
    // list.insert_end(1) ; 
    // msg("Normal List Printing") ; 
    // list.print() ; 

    // msg("Deleting all the values of 1 in the list") ; 
    // list.delete_all_nodes_with_key(1) ; 
    // list.print() ; 

    // msg("Delete Even Positions") ; 
    // list.delete_even() ; 
    // list.print() ; 

    // msg("Delete Odd Positions") ; 
    // list.delete_odd() ; 
    // list.print() ; 
    
    msg("Is this list palindrome !!!") ; 
    list.insert_end(1) ; 
    list.insert_end(2) ; 
    list.insert_end(2) ; 
    list.insert_end(1) ; 
    cout<<boolalpha<<list.is_palindrome() ; // TRUE 
}

int main(){
    // basic1() ; 
    basic2() ; 

    cout<<"\nNO RTE \n" ; 
    return 0 ;
}
