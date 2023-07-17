#ifndef _STKQ_
#define _STKQ_

#include"cqueue.hpp"

class StackQ{
    private: 
        CQ cq ; 
        int add_elements { }  ; 

        void insert_front(int value){
            assert(!cq.IsFull()) ; 
            int sz = add_elements ;
            cq.enqueue(value) ; 
            while(sz--){
                cq.enqueue(cq.dequeue()) ; 
            }
            ++add_elements ; 
        }
    public:
        StackQ(int size) : cq(size){}

        void push(int value){
            insert_front(value) ; 
        }

        int pop(){
            --add_elements ; 
            return cq.dequeue() ; 
        }
        int peek(){
            return cq.front_element() ; 
        }
        bool IsEmpty(){
            return cq.IsEmpty() ; 
        }    
        bool IsFull(){
            return cq.IsFull() ;
        }
} ; 


#endif