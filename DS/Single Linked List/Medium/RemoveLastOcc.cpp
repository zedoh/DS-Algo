#include "../List.hpp"

void List::RemoveLastOcc(int value)
{
    if (!length)
        return;

    Node *delete_my_next_node = nullptr;
    bool is_found = false;

    for (Node *curr = head, *prv = nullptr; curr; prv = curr, curr = curr->next)
    {
        if (curr->data == value)
        {
            is_found = true , delete_my_next_node = prv ;
         }
      }
      if(is_found){
         if (delete_my_next_node)
            delete_next_node(delete_my_next_node);
         else{
            pop_front()  ;
         }
      }
      debug_verify_data_integrity() ;
}