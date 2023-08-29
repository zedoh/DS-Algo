#include "../List.hpp"

int List::max(){
    Node*curr = head ;
    int MaxValue = curr->data ; 
    int NextVal=curr->next->data  ;
    if (!curr || curr == tail->next)
        return 0; 
    MaxValue = std::max(MaxValue , NextVal) ; 
    return MaxValue ; 
}