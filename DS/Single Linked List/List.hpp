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
   }
   void print()
   {
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
     if(empty() || n < 1 || n>length) return nullptr ; 
     Node *temp = head  ; 
     int cnt {0} ;

   while(cnt != n){
      cnt ++ ; 
      temp = temp -> next ; 
   }
     return temp ; 
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
};
#endif