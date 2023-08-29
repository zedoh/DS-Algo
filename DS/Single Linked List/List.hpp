#ifndef _LIST_
#define _LIST_
#include <cassert>
#include <algorithm>
#include <sstream>
#include <string>
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
   Node(int data) : data(data)  , next(nullptr) {}
};

class List
{
private:
   Node *head{};
   Node *tail{};
   int length{0};

   std::vector<Node *> debug_data; // add/remove nodes you use

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

   void delete_node(Node *node)
   {
      debug_remove_node(node);
      --length;
      delete node;
   }

  void delete_next_node(Node* node) {
		// Delete the next of the current node
		// Handle if next is tail case
		assert(node);

		Node* to_delete = node->next;
		bool is_tail = to_delete == tail;

		// node->next in middle to delete
		node->next = node->next->next;

		delete_node(to_delete);
		if (is_tail)
			tail = node;
	}
 

   void add_node(Node *node)
   {
      debug_add_node(node);
      ++length;
   }

   //Utility function to return the idx of a certain node.
   int get_idx(Node*node){
      if(length == 0) return -1 ; 
      
      int count{0} ; 
      for(Node *curr = head ; curr ; curr=curr->next){
         if(node == curr){
            return count ; 
         }
         ++count ; 
      }
      return -1 ; 
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
      }
      else
      {
         tail->next = item;
         tail = item;
         tail->next = nullptr;
      }
      add_node(item) ;
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

   void insert_front(int value) ; 
   void pop_front() ; 
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
         debug_add_node(curr);
         return;
      }
      else if (idx == 1)
      {
         insert_front(value);
         debug_add_node(curr);
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
         debug_remove_node(head);
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
            debug_remove_node(temp);
            delete temp;
            temp = nullptr;
         }
         else if (idx == length)
         {
            Node *temp = get_nth(idx - 1);
            debug_remove_node(tail);
            delete tail;
            tail = temp;
            tail->next = nullptr;
         }
         else
         {
            Node *temp = get_nth(idx - 1);
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            debug_remove_node(toDelete);
            delete toDelete;
            toDelete = nullptr;
         }
      }
      --length;
   }
   int value_from_end(int value) ; 
   void remove_value(int value)
   {
      if (length == 0)
      {
         empty_list();
      }
      if (value == head->data)
      {
         debug_remove_node(head);
         pop_front();
         return;
      }

      if (value == tail->data)
      {
         debug_remove_node(tail);
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

   // Compare between 2 lists
   bool is_same(List &a) ; 
   // Deleting a node using a value
   void delete_node_with_key(int value)
   {
      if(length<0)return ; 
      else if(head->data ==value){
         head = tail =nullptr ; 
      }
      else{
         for(Node* curr = head->next , *prv = head ; curr; curr=curr->next){
            if(curr->data == value){
               delete_next_node(prv)  ; 
               break; 
            }
            prv = prv->next ; 
         }
      }
   }
   // Swap each pair values
   void swap_pairs()
   {
      if (length == 0)
      {
         std::cout << "Empty List" << '\n';
         return;
      }
      int len = length;
      len /= 2;
      for (Node *curr = head; curr; curr = curr->next)
      {
         if (len == 0)
         {
            break;
         }
         std::swap(curr->data, curr->next->data);
         --len;
         curr = curr->next;
      }
   }

   void reverse()
   {
      if (length <= 1)
         return;

      tail = head;
      Node *prv = head;
      head = head->next;

      while (head)
      {
         Node *next = head->next;
         head->next = prv;
         prv = head;
         head = next;
      }
      head = prv;
      tail->next = nullptr;
      debug_verify_data_integrity();
   }

   // Deleting even positions
   void delete_even()
   {
      if (length <= 1)
         return;

      for (Node *curr = head->next, *prv = head; curr;)
      {
         delete_next_node(prv);
         if (!prv->next)
            break;
         curr = prv->next->next;
         prv = prv->next;
      }
      debug_verify_data_integrity();
   }

   void insert_sorted(int value)
   {
      Node *temp = new Node(value);
      if (length == 0)
      {
         head = temp;
         debug_add_node(head);
         head->next = nullptr;
         tail = head;
         ++length;
         return;
      }
      if (length == 1)
      {
         debug_add_node(temp);
         tail = temp;
         head->next = tail;
         tail->next = nullptr;
         ++length;
         return;
      }
      if (temp->data >= tail->data)
      {
         tail->next = temp;
         debug_add_node(temp);
         tail = temp;
         tail->next = nullptr;
         ++length;
         return;
      }

      int count{0};
      for (Node *curr = head->next, *prv = head; curr; curr = curr->next)
      {
         if (temp->data <= curr->data && temp->data >= prv->data)
         {
            prv->next = temp;
            temp->next = curr;
            debug_add_node(temp);
            ++length;
            break;
         }
         prv = prv->next;
         ++count;
      }
      debug_verify_data_integrity();
   }

   //----------------------------------Meduim Challanges---------------------//
   void swap_head_tail(){
      if(length <= 1){
         return;
      }
      else{
         Node *beforeLast = get_nth(length-1) ; 
         Node *tempHead = head; 
         tail->next = head->next ; 
         beforeLast->next = head;
         head = tail   ; 
         tail = tempHead ;
         tail->next = nullptr ; 
         return ;
      }
   }

   
   void rotate_left(long long  k){
      k = k%length ; 
      if (length == 0) return ; 
      else{
         for(long long i = 0 ; i < k ; ++i){
            Node*prv = get_nth(2) ; 
            tail->next = head; 
            head->next = nullptr ; 
            tail = head; 
            head = prv ; 
           tail->next = nullptr ;  
         }
         return ; 
      }
   }

   void remove_duplicates_from_not_sorted() {		// O(n^2) time - O(1) memory
		if (length <= 1)
			return;
			
		// Just like 2 nested loops, find all duplicates and delete

		for (Node *cur1 = head; cur1; cur1 = cur1->next) {
			for (Node *cur2 = cur1->next, *prv = cur1; cur2;) {
				if(cur1->data == cur2->data) {
					delete_next_node(prv);
					cur2 = prv->next;
				} else
					prv = cur2, cur2 = cur2->next;	// normal move
         
			}
		}
		debug_verify_data_integrity();
	}

   void RemoveLastOcc(int value);
   void MoveBack(int value); // Medium Problems - #Problem (5) , Implementation Separated in other file  [Studying OOP :) ] 
   int max() ; //Recursive Function to return the max value
};

#endif
