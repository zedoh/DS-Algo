#include<iostream>
#include"BinaryTree.hpp"

using namespace std ; 



void test1(){
    BinaryTree tree(1) ;
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 19}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    tree.print_inorder() ; 

    cout<<"Max Value: "<<tree.MaxValue() ; 
    cout<<'\n' ;  
    cout<<"Max Depth: "<<tree.MaxDepth() ; 
}

int main(){
    test1() ; 
    return 0 ; 
}