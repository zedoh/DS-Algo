#ifndef _STACK_
#define _STACK_
#include<iostream>
#include<cassert>


class Stack{
    private:
        int *array{ } ; 
        int top{} ; 
        int size{} ;
        int capacity {} ;  

        void expand_size(){
            capacity *= 2;
            int *arr2 = new int [capacity]{ } ; 

            for(int i = 0 ; i < size  ; ++i){
                arr2[i] = array[i] ; 
            }
            std::swap(array ,arr2) ; 
            delete [] arr2 ; 
        }

    public:
        Stack(int size) : size(size), top(-1) , capacity(size)
        {
            array = new int[size];
        }


        ~Stack(){
            delete [] array ; 
        }
        
        bool is_empty(){
            return top == -1  ; 
        }    

        bool is_full(){
            return top  == size-1;
        }

        void display(){
            assert(!is_empty()) ; 
            for(int i= top ; i >= 0 ; i--){
                std::cout<<array[i]<<'\t' ; 
            }std::cout<<'\n' ; 
        }

        void push(int value){
            // if(is_full()){
            //     expand_size() ; 
            // }
            array[++top] = value ;
        }

        int peek(){
            return array[top] ; 
        }

        void pop(){
            assert(!is_empty()) ; 
            --top ; 
        }
} ; 











#endif