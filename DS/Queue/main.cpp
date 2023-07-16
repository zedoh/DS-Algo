#include<iostream>
#include"cqueue.hpp" // Circular Queue
#include"Queue.hpp"
#include "Lqueue.hpp"
using namespace std  ; 

void printLine(const string &text){
    cout<<"\n-----------------------------------------------------------------------------\n" ; 
    cout<<text ; 
    cout<<"\n-----------------------------------------------------------------------------\n" ; 
}

void basic(){
    queue q;
    q.enqueue(1) ;  
    q.enqueue(2) ;  
    q.enqueue(3) ;  
    q.enqueue(4) ;  
    q.enqueue(5) ;  
    q.enqueue(6) ;  
    q.enqueue(7) ;  
    q.enqueue(8) ;  
    q.enqueue(9) ;  
    q.enqueue(10) ;  

    printLine("Normal Printing for the queue") ; 
    q.display() ; 
    printLine("Dequeue an Element from the queue") ; 
    q.dequeue() ; 
    q.display() ; 

    cout<<"Front Element is : "<<q.frontQueue()<<"\tLast Element is : "<<q.rearQueue()<<'\n' ; 
    cout<<"Is this queue full ? "<<boolalpha<<q.isFull() ; // True if reached initially to 10 elements !!! 
}

void circular(){
    CQ cq(3) ; 
    cq.enqueue(1) ; 
    cq.enqueue(2) ; 
    // cq.enqueue(4) ;

    printLine("Normal Print")  ; 
    cq.display() ; 

    // printLine("Remove an Element and display") ; 
    // cq.dequeue() ; 
    // cq.display() ; 

    // cq.enqueue(33) ; 
    // cq.display() ; 
}

void LinkedQueue(){
    LQueue lq  ; 
    lq.enqueue(1) ;
    lq.enqueue(2) ;
    lq.enqueue(3) ;
    lq.enqueue(4) ;

    printLine("Normal Print") ; 
    lq.display() ; 

    cout<<"Front "<<lq.front()<<'\t'<<"Rear "<<lq.rear()<<'\n' ;

    printLine("Deleting an Element")  ; 
    lq.dequeue() ; 
    lq.display() ; 

    cout<<"Front "<<lq.front()<<'\t'<<"Rear "<<lq.rear()<<'\n' ;

}


int main(){
    // basic() ; 
    // circular() ; 
    LinkedQueue() ; 

    cout<<"\nNo RTE\n" ; 
    return  0 ; 
}