#ifndef _DSTACK_
#define _DSTACK_
#include<iostream>
#include<cassert>

class Dstack{
    private:
        int *arr{ };
        int top {} ; 
        int top2{} ; 
        int size{} ; 

    public:

    Dstack(int size):size(size),top(-1) , top2(size){
        arr = new int [size] ;    
    }

    ~Dstack(){
        delete[] arr ; 
    }
    //"idx" referes to the number of stack. 1 , 2 ???
    bool ValidIndex(int idx){
        if(idx<1 || idx>2)return false ; 
        return true ; 
    }    

    bool IsEmpty(int idx){
        if(idx ==2 && top2 == size) return true ; 
        if(idx == 1 && top == -1) return true;
        return false ; 
    }


    void push(int idx  , int value){
        assert(ValidIndex(idx)) ; 
        if(idx == 1){
            arr[++top] = value ; 
        }else if(idx == 2) {
            arr[--top2] = value ; 
        }
    }

    void pop(int idx){
        assert(!IsEmpty(idx)) ; 
        assert(ValidIndex(idx)) ;

        if(idx == 1) arr[--top] ; 
        else arr[++top2] ; 
    }

    int peek(int idx){
        assert(ValidIndex(idx)) ; 
        assert(!IsEmpty(idx)) ; 

        if(idx == 1)return arr[top] ; 
        else return arr[top2] ; 
    }

    void display(int idx){
        assert(!IsEmpty(idx)) ; 
        assert(ValidIndex(idx)) ; 

        if(idx == 1){
            for(int i = top ; i >= 0 ; i-- ){
                std::cout<<arr[i]<<'\t'  ; 
            }
            std::cout<<'\n' ; 
        }else{
            for(int i = top2 ; i<=size-1 ; i++){
                std::cout<<arr[i]<<'\t' ; 
            }std::cout<<'\n' ; 
        }
    }
} ; 




#endif