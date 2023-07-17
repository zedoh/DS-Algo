#ifndef _2STK_
#define _2STK_
#include"../Stack/STACK.hpp"

// O(1) in Dequeue function Implementation
class QUEUE{
    private : 
        Stack st1 , st2 ;
        int add_elements {0} ; 
        int size{0} ; 

       void Move(Stack& s1 , Stack& s2){
            while (!s1.is_empty()){
                s2.push(s1.peek()) ; 
                s1.pop() ; 
            }
        }

        public:
            QUEUE(int size) : size(size), st1(size), st2(size) {}

            //------------------------------------O(1) in Dequeue-------------------------//
            /*
                       void enqueue(int value){
                           Move (st2,st1) ;
                           st1.push(value) ;
                           Move(st1 , st2) ;
                           add_elements++ ;
                       }

                       int dequeue(){
                           assert(!IsEmpty()) ;
                           int value  = st2.peek() ;
                           st2.pop() ;
                           --add_elements ;
                           return value ;
                       }
               */
            //---------------------------------------O(1) in Enqueue----------------------------------//
            void enqueue(int value){
                st1.push(value) ; 
                add_elements++  ; 
            }

            int dequeue(){
                assert(!IsEmpty()) ; 
                Move(st1,st2) ; 
                int value  = st2.peek() ; 
                st2.pop() ; 
                --add_elements ; 
                return value  ; 
            }
            bool IsFull()
            { // Based on a  Dynamic Stack Implementation No need to check :(
            return add_elements == size ;
        }
        
        bool IsEmpty(){
            return add_elements == 0 ; 
        }
        
    }; 


#endif