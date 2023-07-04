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

    // msg("INSERT END");
    // list.insert_end(11) ; 
    // list.insert_end(2) ;  
    // list.insert_end(3) ;  
    // list.insert_end(4) ;  
    // list.insert_end(5) ;  

    // msg("INSERT FRONT") ; 
    // list.insert_front(10000) ;
    // list.insert_front(20000) ;
    // list.insert_front(30000) ;
    // list.insert_front(40000) ;

    msg("INSERT SORTED") ; 
    list.insert_sorted(10) ; 
    list.insert_sorted(15) ; 
    list.insert_sorted(1) ; 
    list.insert_sorted(22312) ; 
    list.insert_sorted(500) ; 
    list.print() ; 

    // msg("Deleting the front of 3 elements") ; 
    // list.delete_front() ; 
    // list.delete_front() ; 
    // list.delete_front() ; 
    // list.print() ; 


    msg("Deleting the last 2 elements in the list") ; 
    list.delete_end() ; 
    list.delete_end() ; 
    list.print() ; 
}

int main(){
    basic1() ; 

    cout<<"\nNO RTE \n" ; 
    return 0 ;
}
