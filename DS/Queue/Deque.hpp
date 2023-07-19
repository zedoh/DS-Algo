#ifndef _DQ_
#define _DQ_
#include<iostream>
#include<cassert>


class Deque{
    private:
        int size{ } ; 
        int front{0} ; 
        int rear {0} ;
        int added_elements { } ; 
        int *arr{ } ; 
    public:
        Deque(int size) : size(size){
            arr = new int [size] ; 
        }
        ~Deque(){
            delete [] arr ; 
        }

        int next(int idx){
            ++idx  ; 
            if(size == idx)
                idx = 0 ; 
            return idx ; 
        }

        int prev(int idx){
            --idx ; 
            if(idx == -1)
                idx == size-1 ; 
            return idx ; 
        }

        void enqueue_rear(int value){
            assert(!IsFull()) ;
            arr[rear] = value ; 
            rear = next(rear) ; 
            ++added_elements ; 
        }

        void enqueue_front(int value){
            assert(!IsFull()) ; 
            front = prev(front)  ; 
            arr[front] = value ; 
            ++added_elements ; 
        }

        int  dequeue_front(){
            assert(!IsEmpty()) ; 
            int value = arr[front] ; 
            front = next(front) ; 
            --added_elements ; 
            return value ; 
        }

        int dequeue_rear(){
            assert(!IsEmpty())  ; 
            int value = arr[rear]  ; 
            rear = prev(rear) ; 
            --added_elements ; 
            return value ; 
        }

        void display(){
           std::cout<<"Front "<<front<<" - rear "<<rear<<'\t' ; 

           if(IsEmpty()){
            std::cout<<"Empty\n" ;
            return ; 
           } else if(IsFull()){
            std::cout<<"Full\n" ; 
           }

           for (int step = 0, curr = front; step < added_elements; step++, curr = next(curr))
           {
            std::cout << arr[curr] << "\t";
           }
           std::cout << "\n";
        }

        bool IsFull(){
            return added_elements == size ; 
        }
        
        bool IsEmpty(){
            return added_elements == 0 ; 
        }
} ; 




#endif