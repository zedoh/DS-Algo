#include "../List.hpp"

int List::max(Node *curr){
    if(!curr){
        return INT_MIN; 
    }
    int MaxValue  = curr->data ; 
    return std::max(MaxValue , this->max(curr->next)) ; 
}