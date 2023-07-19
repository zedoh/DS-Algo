#ifndef _LQ_
#define _LQ_

#include"../Single Linked List/List.hpp"

class LQueue{
    List list;

public: 

    void enqueue(int value){
        list.insert_end(value) ; 
    }

    void dequeue(){
        list.pop_front() ; 
    }

    bool IsEmpty(){
        return list.empty() ; 
    }

    void display(){
        list.print() ; 
    }
    
    int front(){
        return list.front() ; 
    }

    int rear(){
        return list.back() ; 
    }
    
} ; 

#endif