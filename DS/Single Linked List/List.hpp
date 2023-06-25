#ifndef _LIST_
#define _LIST_
#include <cassert>
#include <iostream>
#include <vector>
    // Code Complexity
    // Space Complextiy : O(N)

    // Time Complexity : O(N)
    struct Node
{
   int data;
   Node *next;
   Node(int data) : data(data) {}
};

class List
{
private:
   Node *head{};
   Node *tail{};
   int length{0};

public:
   // TODO : DESTRUCTOR ERROR
   ~List()
   {
      Node *curr = head;
      while (curr)
      {
         Node *temp = curr->next;
         delete curr;
         curr = temp;
      }
      head = nullptr;
      tail = nullptr;
   }
   // Utility function to return nothing whenever list is empty
   void empty_list()
   {
      if (length == 0)
      {
         std::cout << "The list is empty !!" << std::endl;
         return;
      }
   }
   void print()
   {
      if (length == 0)
      {
         std::cout << "Empty list" << std::endl;
         return;
      }
      for (Node *curr = head; curr; curr = curr->next)
      {
         std::cout << curr->data << "\t";
      }
      std::cout << '\n';
   }

   void insert_end(int value)
   {
      Node *item = new Node(value);
      if (!head)
      {
         head = tail = item;
         tail->next = nullptr;
         ++length;
      }
      else
      {
         tail->next = item;
         tail = item;
         tail->next = nullptr;
         ++length;
      }
   }

   Node *get_nth(int n) // One-Based Index
   {
      if (empty() || n < 1 || n > length)
         return nullptr;
      Node *temp = head;
      int cnt{1};

      while (cnt != n)
      {
         cnt++;
         temp = temp->next;
      }
      return temp;
   }

   int size()
   {
      return length;
   }

   bool empty()
   {
      if (length == 0)
         return true;
      return false;
   }

   void insert_front(int value)
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
      ++length;
   }

   void pop_front()
   {
      assert(length > 0);

      if (length == 1)
      {
         head = tail = nullptr;
      }
      else
      {
         Node *temp = head;
         head = head->next;
         temp = nullptr;
      }
      --length;
   }

   void pop_back()
   {
      if (length == 0)
      {
         std::cout << "Nothing to pop !!" << std::endl;
         return;
      }
      if (length == 1)
      {
         head = tail = nullptr;
      }
      else
      {
         Node *newTail = get_nth(length - 1);
         tail = newTail;
         tail->next = nullptr;
      }
      --length;
   }

   // Get the value of the first element
   int front()
   {
      if (length == 0)
      {
         std::cout << "The list is already empty !! " << std::endl;
         return -1;
      }
      return head->data;
   }

   // Get the value of the last element
   int back()
   {
      if (length == 0)
      {
         std::cout << "The list is already empty !! " << std::endl;
         return -1;
      }
      return tail->data;
   }

   // Insert an element at a specific index with a specific value
   void insert(int idx, int value)
   {
      Node *curr = new Node(value);
      if (idx >= length + 1)
      {
         std::cout << "Out of boundries" << std::endl;
         return;
      }

      if (length == 0 || idx == length)
      {
         insert_end(value);
         return;
      }
      else if (idx == 1)
      {
         insert_front(value);
         return;
      }
      else
      {
         Node *prev = get_nth(idx - 1);
         curr->next = prev->next;
         prev->next = curr;
      }
      length++;
   }

   // Erase a specific element from the list using index
   void erase(int idx)
   {
      if (length == 0)
      {
         std::cout << "There are no elements to delete!" << std::endl;
         return;
      }
      if (length == 1)
      {
         delete head;
         head = nullptr;
         tail = nullptr;
      }
      else
      {
         if (idx == 1)
         {
            Node *temp = head;
            head = temp->next;
            delete temp;
            temp = nullptr;
         }
         else if (idx == length)
         {
            Node *temp = get_nth(idx - 1);
            delete tail;
            tail = temp;
            tail->next = nullptr;
         }
         else
         {
            Node *temp = get_nth(idx - 1);
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            toDelete = nullptr;
         }
      }
      --length;
   }
   int value_from_end(int idx)
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

   // 1 , 2 , 3 , 4 , 5
   // reverse
   // 5 , 4 , 3 , 2 , 1
   // swap(get_nth(i) , get_nth(size-i+1))

  void reverse()
{
   if (length == 0)
   {
      empty_list();
      return;
   }

   for (int i = 1; i <= length / 2; i++)
   {
      Node* curr = get_nth(i);
      Node* reverse = get_nth(length - i + 1);
      std::swap(curr->data, reverse->data);
   }
}
 
   // 11 12 13 14 15
   //value 12 
   // 11 , 13 , 14 , 15 
 void remove_value(int value){
   if (length == 0){
      empty_list() ; 
   }
   if(value == head->data){
      pop_front() ; 
      return  ; 
   }

   if(value ==tail->data){
      pop_back() ; 
      tail = get_nth(length) ; 
      tail->next = nullptr ; 
      return ; 
   }
   int count{1} ; 
   for(Node*curr = head ; curr ; curr = curr->next){
      if(curr->data == value){
         erase(count) ; 
         break ;
      }
      ++count ; 
   }
   --length ; 
 }
};
#endif