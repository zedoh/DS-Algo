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

   int list_size()
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
      if(length == 0 ){
         std::cout<<"Nothing to pop !!"<<std::endl ; 
         return ; 
      }
      if (length == 1)
      {
         head = tail = nullptr;
      }
      else
      {
         Node *newTail = get_nth(length-1) ; 
         tail = newTail ; 
         tail->next=nullptr;
      }
      --length;
   }
};
#endif