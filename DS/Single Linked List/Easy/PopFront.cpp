#include "../List.hpp"

void List::pop_front(){
    assert(length > 0);

    if (length == 1)
    {
        delete_node(head);
        head = tail = nullptr;
        return;
    }
    else if (length == 2)
    {
        delete_node(tail);
        head->next = nullptr;
        tail = head;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete_node(temp);
        temp = nullptr;
        return;
    }
}