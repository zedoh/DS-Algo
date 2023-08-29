#include "../List.hpp"
int List::value_from_end(int idx)
{
    if (idx > length)
    {
        throw std::out_of_range("out of range");
    }
    else if (idx == 1)
    {
        return tail->data;
    }
    else if (idx == length)
    {
        return head->data;
    }
    else if (length == 0)
    {
        throw std::out_of_range("EMPTY !!!");
    }

    // 1 2 3 4 5 ,  n(2) , size(5)
    // return (4) , size (5) , (5)-(2)+1 , size-n+1
    idx = length - idx + 1;
    int count{1};
    for (Node *curr = head; curr; curr = curr->next)
    {
        if (count == idx)
        {
            return curr->data;
         }

         ++count;
      }
      return -1;
}