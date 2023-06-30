# Easy Challanges
## 1. Destructor
```CPP
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
```

## 2. Insert Front
```CPP
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

``` 

## 3. Delete Front
```CPP
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
```

## 4. Get the n_th from back
```CPP
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
```
## 5. Is the same list
```CPP
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
``` 
## 6. Linked list without `length` or  `tail`
```CPP
#ifndef _NOTAIL_
#define _NOTAIL_
#include<iostream>

struct node
{
   int data;
   node *next;
   node(int data) : data(data) {}
};

class NoTailList{
private:
   node *head{};
public: 


   NoTailList() {}
   NoTailList(const NoTailList &) = delete;
   NoTailList &operator=(const NoTailList &another) = delete;
   ~NoTailList()
   {
      node *curr = head;
      while (curr)
      {
         node *temp = curr->next;
         delete curr;
         curr = temp;
      }
      head = nullptr;
   }

   void print(){
      if(head == nullptr){
         return ; 
      }
      for(node *curr = head  ; curr ; curr=curr->next){
         std::cout<<curr->data<<" " ; 
      }
      std::cout<<"\n" ; 
   }


   void add_element(int value){
      if(head == nullptr){
         node *temp = new node(value) ; 
         head  = temp ; 
         head ->next = nullptr ;
         return  ; 
      }
      node*curr = new node(value) ; 
      for(node*temp = head ; temp ; temp = temp->next){
         if(temp->next == nullptr){
            temp->next = curr ; 
            curr->next = nullptr; 
            return; 
         }
      }
   }

   node *getTail()
   {
      //Empty list
      if (head == nullptr)
      {
         return head;
      }
      else
      {
         for (node *temp = head; temp; temp = temp->next)
         {
            if (temp->next == nullptr)
            {
               return temp;
            }
         }
      }
      return nullptr;
   }
} ; 

#endif //_NOTAIL_ 
```

---
# Easy To Medium Challanges
## 1. Delete with key
```cpp
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
```
---
## 2. Swap each pair values 
```cpp
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
```
---
## 3. Reverse List nodes
```CPP
   void reverse(){
      if(length<=1)  return ; 

      tail = head  ; 
      Node* prv = head ; 
      head = head ->next   ; 

      while(head){
         Node *next = head -> next ; 
         head->next = prv ; 
         prv = head ; 
         head = next ; 
      } 
      head = prv ; 
      tail->next = nullptr ; 
      debug_verify_data_integrity() ; 
   }
```
---
## 4. Delete Even Positions
```CPP
   void delete_even(){
      if(length<=1) return ; 

      for(Node *curr = head->next , *prv = head;curr;){
         delete_next_node(prv)  ; 
         if(!prv->next) break ; 
         curr = prv->next->next ; 
         prv = prv->next ; 
      }
      debug_verify_data_integrity();
   }
```
- In this problem , there are 2 utility functions used :
   -  `delete_node(Node *node)` and `delete_next_node(Node *node)` :
    ```CPP
   void delete_node(Node *node){
      debug_remove_node(node);
      --length;
      delete node;
   }

   void delete_next_node(Node *node){
      assert(node) ; 

      Node *toDelete = node->next ; 
      bool isTail  = toDelete == tail  ; 

      node->next = toDelete->next ; 
      delete_node(toDelete) ; 

      if(isTail){
         tail = node ; 
      }
   }
      ```
---
## 5. Insert To Be Sorted
```CPP
   void insert_sorted(int value){
      Node *temp = new Node(value);
      if(length == 0)
      {
         head = temp ; 
         debug_add_node(head) ; 
         head->next = nullptr ; 
         tail = head ; 
         ++length ; 
         return ; 
      }
      if(length == 1){
         debug_add_node(temp) ; 
         tail = temp ; 
         head->next = tail  ; 
         tail->next = nullptr ; 
         ++length ; 
         return ; 
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
            prv->next = temp ; 
            temp->next  = curr ; 
            debug_add_node(temp);
            ++length ; 
            break ; 
         }
         prv = prv->next ; 
         ++count ;
      }
      debug_verify_data_integrity();
   }
```
*`Note`* : I didn't use here the utility functions in some functions , as I solve the problems not in order . 