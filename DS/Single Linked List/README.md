# 1️⃣ Easy Challanges

1. [Destructor](/DS/Single%20Linked%20List/List.hpp#L184-L195) 
2. [Insert Front](/DS/Single%20Linked%20List/Easy/InsertFront.cpp)
3. [Delete Front](/DS/Single%20Linked%20List/Easy/PopFront.cpp)
4. [Get the n_th from back](/DS/Single%20Linked%20List/Easy%20To%20Medium/ValueFromEnd.cpp)
5. [Is the same list](/DS/Single%20Linked%20List/Easy%20To%20Medium/IsSame.cpp)
6. [Linked list without `length` or  `tail`](/DS/Single%20Linked%20List/NoTail.hpp)
---
# 2️⃣ Easy To Medium Challanges
1. [Delete Node With Key](/DS/Single%20Linked%20List/List.hpp#L528-L543)
2. [Swap Each Pair Values](/DS/Single%20Linked%20List/List.hpp#L545-L564)
3. [Reverse List](/DS/Single%20Linked%20List/List.hpp#L566-L585)
4. [Delete Even Positions](/Ds/Single%20Linked%20List/List.hpp#L588-L602)
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
5.  [Insert To Be Sorted](/DS/Single%20Linked%20List/List.hpp#L604-L650)
      - _Note_ : I didn't use here the utility functions in some functions , as I solve the problems not in order . 

---
# 3️⃣ Medium Problems 
1. [Remove Last Occurence](/DS/Single%20Linked%20List/Medium/RemoveLastOcc.cpp)
2. [Move To Back](/DS/Single%20Linked%20List/Medium/MoveToBack.cpp) //TODO
3. [Recursive Max](/DS/Single%20Linked%20List/Medium/max.cpp)