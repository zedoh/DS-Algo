#ifndef _NOTAIL_
#define _NOTAIL_
#include<iostream>

struct node
{
   int data;
   node *next;
   node(int data) : data(data) {}
};

class NoTailList{
private:
   node *head{};
public: 


   NoTailList() {}
   NoTailList(const NoTailList &) = delete;
   NoTailList &operator=(const NoTailList &another) = delete;
   ~NoTailList()
   {
      node *curr = head;
      while (curr)
      {
         node *temp = curr->next;
         delete curr;
         curr = temp;
      }
      head = nullptr;
   }

   void print(){
      if(head == nullptr){
         return ; 
      }
      for(node *curr = head  ; curr ; curr=curr->next){
         std::cout<<curr->data<<" " ; 
      }
      std::cout<<"\n" ; 
   }


   void add_element(int value){
      if(head == nullptr){
         node *temp = new node(value) ; 
         head  = temp ; 
         head ->next = nullptr ;
         return  ; 
      }
      node*curr = new node(value) ; 
      for(node*temp = head ; temp ; temp = temp->next){
         if(temp->next == nullptr){
            temp->next = curr ; 
            curr->next = nullptr; 
            return; 
         }
      }
   }

   node *getTail()
   {
      //Empty list
      if (head == nullptr)
      {
         return head;
      }
      else
      {
         for (node *temp = head; temp; temp = temp->next)
         {
            if (temp->next == nullptr)
            {
               return temp;
            }
         }
      }
      return nullptr;
   }
} ; 

#endif //_NOTAIL_ 
