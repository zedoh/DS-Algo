#include "../List.hpp"


void List::insert_front(int value)
{
      Node *temp = new Node(value);
      if (length == 0)
      {
         head = temp;
         head->next = nullptr;
         tail = head;
      }
      else if (length == 1)
      {
         tail = head;
         head = temp;
         head->next = tail;
         tail->next = nullptr;
      }
      else
      {
         temp->next = head;
         head = temp;
      }
      debug_add_node(temp);
      ++length;
}