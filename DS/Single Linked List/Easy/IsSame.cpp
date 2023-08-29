#include "../List.hpp"

bool List::is_same(List &a)
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