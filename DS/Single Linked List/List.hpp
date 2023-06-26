#ifndef _LIST_
#define _LIST_
#include <cassert>
#include <algorithm>
#include <sstream>
#include<string>
#include <climits>
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
   Node *head{ };
   Node *tail{ };
   int length{0};

   std::vector <Node*> debug_data; // add/remove nodes you use

   void debug_add_node(Node *node)
   {
      debug_data.push_back(node);
   }
   void debug_remove_node(Node *node)
   {
      auto it = std::find(debug_data.begin(), debug_data.end(), node);
      if (it == debug_data.end())
         std::cout << "Node does not exist\n";
      else
         debug_data.erase(it);
   }

public:
   List() {}
   List(const List &) = delete;
   List &operator=(const List &another) = delete;

   void debug_print_address()
   {
      for (Node *cur = head; cur; cur = cur->next)
         std::cout << cur << "," << cur->data << "\t";
      std::cout << "\n";
   }

   void debug_print_node(Node *node, bool is_seperate = false)
   {
      if (is_seperate)
         std::cout << "Sep: ";
      if (node == nullptr)
      {
         std::cout << "nullptr\n";
         return;
      }
      std::cout << node->data << " ";
      if (node->next == nullptr)
         std::cout << "X ";
      else
         std::cout << node->next->data << " ";

      if (node == head)
         std::cout << "head\n";
      else if (node == tail)
         std::cout << "tail\n";
      else
         std::cout << "\n";
   }
   void debug_print_list(std::string msg = "")
   {
      if (msg != "")
         std::cout << msg << "\n";
      for (int i = 0; i < (int)debug_data.size(); ++i)
         debug_print_node(debug_data[i]);
      std::cout << "************\n"
                << std::flush;
   }

   std::string debug_to_string()
   {
      if (length == 0)
         return "";
      std::ostringstream oss;
      for (Node *cur = head; cur; cur = cur->next)
      {
         oss << cur->data;
         if (cur->next)
            oss << " ";
      }
      return oss.str();
   }

   void debug_verify_data_integrity()
   {
      if (length == 0)
      {
         assert(head == nullptr);
         assert(tail == nullptr);
         return;
      }

      assert(head != nullptr);
      assert(tail != nullptr);
      assert(tail->next == nullptr);

      if (length == 1)
         assert(head == tail);
      else
      {
         assert(head != tail);

         if (length == 2)
            assert(head->next == tail);
         else if (length == 3)
         {
            assert(head->next);
            assert(head->next->next == tail);
         }
      }
      int len = 0;
      Node *prev = nullptr;
      for (Node *cur = head; cur; prev = cur, cur = cur->next, len++)
         assert(len < 10000); // Consider infinite cycle?

      assert(length == len);
      assert(length == (int)debug_data.size());
      assert(prev == tail); // last node is tail
   }
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
         std::cout << "The list is empty !!" << '\n';
         return;
      }
   }
   void print()
   {
      if (length == 0)
      {
         std::cout << "Empty list" << '\n';
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
      debug_add_node(item) ; 
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
      debug_add_node(temp) ; 
      ++length;
   }

   void pop_front()
   {
      assert(length > 0);

      if (length == 1)
      {
         debug_remove_node(head) ; 
         head = tail = nullptr;
      }
      else
      {
         Node *temp = head;
         debug_remove_node(temp);
         head = head->next;
         temp = nullptr;
      }
      --length;
   }

   void pop_back()
   {
      if (length == 0)
      {
         std::cout << "Nothing to pop !!" << '\n';
         return;
      }
      if (length == 1)
      {
         debug_remove_node(head);
         head = tail = nullptr;
      }
      else
      {
         Node *newTail = get_nth(length - 1);
         debug_remove_node(newTail->next);
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
         std::cout << "The list is already empty !! " << '\n';
         return -1;
      }
      return head->data;
   }

   // Get the value of the last element
   int back()
   {
      if (length == 0)
      {
         std::cout << "The list is already empty !! " << '\n';
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
         std::cout << "Out of boundries" << '\n';
         return;
      }

      if (length == 0 || idx == length)
      {
         insert_end(value);
         debug_add_node(curr) ; 
         return;
      }
      else if (idx == 1)
      {
         insert_front(value);
         debug_add_node(curr) ; 
         return;
      }
      else
      {
         Node *prev = get_nth(idx - 1);
         curr->next = prev->next;
         prev->next = curr;
      }
      debug_add_node(curr);
      length++;
   }

   // Erase a specific element from the list using index
   void erase(int idx)
   {
      if (length == 0)
      {
         std::cout << "There are no elements to delete!" << '\n';
         return;
      }
      if (length == 1)
      {
         debug_remove_node(head) ; 
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
            debug_remove_node(temp) ; 
            delete temp;
            temp = nullptr;
         }
         else if (idx == length)
         {
            Node *temp = get_nth(idx - 1);
            debug_remove_node(tail) ; 
            delete tail;
            tail = temp;
            tail->next = nullptr;
         }
         else
         {
            Node *temp = get_nth(idx - 1);
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            debug_remove_node(toDelete) ; 
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
         Node *curr = get_nth(i);
         Node *reverse = get_nth(length - i + 1);
         std::swap(curr->data, reverse->data);
      }
   }

   // 11 12 13 14 15
   // value 12
   // 11 , 13 , 14 , 15
   void remove_value(int value)
   {
      if (length == 0)
      {
         empty_list();
      }
      if (value == head->data)
      {
         debug_remove_node(head) ; 
         pop_front();
         return;
      }

      if (value == tail->data)
      {
         debug_remove_node(tail) ; 
         pop_back();
         tail = get_nth(length);
         tail->next = nullptr;
         return;
      }
      int count{1};
      for (Node *curr = head; curr; curr = curr->next)
      {
         if (curr->data == value)
         {
            erase(count);
            break;
         }
         ++count;
      }
      --length;
   }
   
   //Compare between 2 lists
   bool is_same(List &a)
   {
      if (size() != a.size())
      {
         return false;
      }
      Node *curr = head;
      Node *aCurr = a.head;

      while (curr != nullptr && aCurr != nullptr)
      {
         if (curr->data != aCurr->data)
         {
            return false;
         }
         curr = curr->next;
         aCurr = aCurr->next;
      }

      return true;
   }
};
#endif