#include<iostream>
#include"BinaryTree.hpp"

using namespace std ; 



void test1(){
    BinaryTree tree(1) ;
    tree.add({2,3,4,5} , {'L' , 'R' , 'L' , 'L' }) ; 
    tree.add({2,3,6,22} , {'L' , 'R' , 'R' , 'L' }) ; 
    tree.add({33,5,44,222} , {'R' , 'L' , 'L' , 'R' }) ; 

    tree.print_inorder() ; 

    cout<<"Max Value: "<<tree.MaxValue() ; 
    cout<<'\n' ;  
    cout<<"Max Depth: "<<tree.MaxDepth() ; 
    cout<<"\nHow many nodes in that tree : "<<tree.Nodes() ; 
    cout<<"\nHow many levels are the current tree : "<<tree.TreeLevels() ; 
    cout<<"\n\n Is this tree a perfect tree : "<<boolalpha<<tree.IsPerfect() ; 
    cout<<"\n--------------------------------------------------------------------\n" ; 
    cout<<"\n\tTesting Level Traversing Function \n" ; 
    tree.LevelTraversal() ; 
    cout<<"What is the summation of the all values in this tree ? \n" ; 
    cout<<"Sum = "<<tree.SumofTheTree() <<'\n'; 
}

void test2(){
    BinaryTree tree(1) ;
    tree.add({2,3,4,5} , {'L' , 'R' , 'L' , 'L' }) ; 
    tree.add({2,3,6,22} , {'L' , 'R' , 'R' , 'L' }) ; 
    tree.add({33,5,44,222} , {'R' , 'L' , 'L' , 'R' }) ; 
    cout<<"Printing the tree in the parenthizing style : \n" ; 
    cout<<tree.TreeParenth()<<"\n" ; 

}

int main(){
    // test1() ; 
    test2() ; 
    return 0 ; 
}
