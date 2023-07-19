#ifndef _LSTACK_
#define _LSTACK_
#include <iostream>
#include <cassert>

struct Node
{
  int data;
  Node *next;
  Node(int data) : data(data) {}
};

class Lstack
{
private:
  Node *head{};

public:
  Lstack() : head(nullptr) {}

  ~Lstack()
  {
    Node *curr = head;
    Node *temp = nullptr;
    while (curr)
    {
      temp = curr->next;
      delete curr;
      curr = temp;
    }
    curr = nullptr;
    temp = nullptr;
  }

  void push(int value)
  {
    if (!head)
    {
      Node *temp = new Node(value);
      head = temp;
      head->next = nullptr;
    }
    else
    {
      Node *temp = new Node(value);
      temp->next = head;
      head = temp;
    }
  }

  void pop()
  {
    assert(head);
    Node *prv = nullptr;
    Node *todelete = head;
    head = todelete->next;
    delete todelete;
    todelete = nullptr;
  }

  void display()
  {
    assert(head);

    for (Node *curr = head; curr; curr = curr->next)
    {
      std::cout << curr->data << '\t';
    }
    std::cout << '\n';
  }

  int top()
  {
    assert(head);
    return head->data;
  }
};

#endif