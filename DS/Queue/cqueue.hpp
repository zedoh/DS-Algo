#ifndef _CQ_
#define _CQ_
#include<iostream>
#include<cassert>

class CQ{
    public:
        int front {0} ; 
        int rear {0} ; 
        int *arr { } ; 
        int capacity{} ; 
        int added_elements{0} ; 

    CQ(int size):capacity(size){
       arr =  new int [capacity]{ } ; 
    }

    ~CQ(){
       delete[] arr;
    }

    int next(int idx){
        ++idx;
        if(idx == capacity)
            idx = 0 ; 
        return idx  ;
    }

    void enqueue(int value){
        assert(!IsFull()) ; 
        arr[rear] = value; 
        rear = next(rear) ; 
        added_elements++ ; 
    }

    int dequeue (){
        assert(!IsEmpty()) ; 
        int value = arr[front] ; 
        front  = next(front) ; 
        --added_elements ; 
        return value ; 
    }

    int front_element(){
        assert(!IsEmpty()) ; 
        return arr[front]; 
    }
    int rear_element(){
        assert(!IsEmpty()) ; 
        return arr[rear] ; 
    }
    void display(){
        std::cout<<"Front : "<<front<<" , Rear : "<<rear<<'\t' ;
        if (IsFull())
            std::cout << "Full";
        else if (IsEmpty()){
            std::cout<<"Empty\n\n" ; 
            return ; 
        }std::cout<<'\n' ;

        for(int curr = front , step = 0 ; step < added_elements ; ++step , curr = next(curr))
            std::cout<<arr[curr]<<" " ; 
        std::cout<<'\n' ;  
    }

    bool IsEmpty(){
        return added_elements==0 ; 
    }
    bool IsFull(){
        return added_elements == capacity ; 
    }

    
} ; 

#endif
