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
