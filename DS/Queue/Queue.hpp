#ifndef _AQ_ // Array based queue 
#define _AQ_

#include<iostream>
#include<cassert>

class queue{
private:
   int *arr{};
   int size{};
   int front{};
   int capacity{};

public:
   queue() : size(0), capacity(size + 10) , front(-1)
   {
      arr = new int[capacity]{ };
   }

   void expand(){ //Time : O(N) , Space : O(N)
      capacity *= 2;
      int *arr2 = new int[capacity]{};

      for (int i = 0; i < size; ++i)
      {
         arr2[i] = arr[i];
      }
      std::swap(arr, arr2);
      delete[] arr2;
   }

   ~queue(){
      delete[] arr;
   }

   int frontQueue(){
      return arr[front] ; 
   }
   
   int rearQueue(){
      return arr[size-1]  ; 
   }

   bool isFull(){
      return size==capacity ; 
   }

   bool isEmpty(){
      return size==0 ; 
   }

   void enqueue(int value){
      if(isFull()){
         expand() ; 
      }
      arr[size++] = value ; 
      front = 0   ; 
   }

   void dequeue(){ //Time : O(N) , Space : O(N)
      assert(!isEmpty()) ; 

      for(int i = 0 ; i < size ; i++){
         arr[i] = arr[i+1] ; 
      }
      --size ; 
      front = arr[0] ; 
   }
   
   void display(){ // Time : O(N) , Space : O(N) 
      assert(!isEmpty()) ; 
      for(int i = front ; i < size ; ++i){
         std::cout<<arr[i]<<'\t' ; 
      }
      std::cout<<'\n' ; 
      return ; 
   }
   
} ; 


#endif