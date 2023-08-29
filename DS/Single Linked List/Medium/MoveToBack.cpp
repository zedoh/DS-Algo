#include "List.hpp"

void List::MoveBack(int value){
      if(length <= 1)
         return;

      if(head->data == value) {
         insert_end(value) ; 
         pop_front() ; 
      }else{
      for(Node *curr=  head , *prv= head  ; curr ; curr=curr->next){  
         if(curr->data == value && curr !=tail){
            delete_next_node(prv) ; 
            insert_end(value) ;
         }
         prv = prv->next;
      }
      }
   }