#include"BST.hpp"
using namespace std ; 


void test1(){
    BST bst(16) ; 
    bst.insert(10) ; 
    bst.insert(1) ; 
    bst.insert(12) ; 
    bst.insert(3) ; 
    bst.insert(4) ; 
    bst.insert(5) ; 
    bst.insert(144) ; 
    bst.insert(98) ; 

    bst.print() ; 

    cout<<"Do we have the value 144 ? \t --> "<<boolalpha<<bst.search(144)<<'\n' ;

    cout<<"Do we have the value 33 ? \t --> "<<boolalpha<<bst.search(33)<<'\n' ;

    bst.Delete(5) ; 
    bst.print() ; 
    cout<<boolalpha<<bst.CheckTree()<<'\n' ; 
}


int main(){

    test1() ; 

    cout<<"\nNo RTE\n" ;  
    return 0 ; 
}