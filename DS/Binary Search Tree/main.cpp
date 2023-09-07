#include "Bst.hpp"
using namespace std ;



void Test1(){

    BST bst(15) ; 
    bst.insert(20) ; 
    bst.insert(6) ; 
    bst.insert(8) ; 
    bst.insert(1) ; 
    bst.insert(10) ; 
    bst.insert(14) ; 
    bst.insert(9) ;

    bst.print(); 
    cout<<"\nGetting the right child for the value \""<<15<<"\" : "<<bst.GetChild(15 , "right")<<'\n'  ; 
    cout<<"\nGetting the parent of the value \""<<10<<"\" : "<<bst.GetParent(10)<<'\n' ; 
    cout<<"\nMaximum Value is : "<<bst.maxValue()<<'\n' ; 
    cout<<"\nMinimum Value is : "<<bst.minValue()<<'\n' ; 
    cout<<"\nDeleting the node with the value 10 \n"  ; 
    bst.Delete(10) ; 
    bst.print() ; 

}


int main(){
    Test1() ; 
    cout<<"\nN0 RTE\n" ; 


    return 0 ; 
}