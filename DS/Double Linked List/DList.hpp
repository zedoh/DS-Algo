#ifndef _DLIST_
#define _DLIST_

#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <vector>

struct Node
{
    int data;
    Node *next{};
    Node *prev{};
    Node(int data) : data(data) {}
};

class DList
{
private:
    Node *head{};
    Node *tail{};
    int length{0};

public:
    DList() {}
    DList(const DList &) = delete;
    DList &operator=(const DList &another) = delete;
    ~DList()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    //-----------------------------Debuging TOOLS----------------------------------------------//
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


    void delete_node(Node *node)
    {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void delete_next_node(Node *node)
    {
        // Delete the next of the current node
        // Handle if next is tail case
        assert(node);

        Node *to_delete = node->next;
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


    //-----------------------UTILITY----------------------------------------//
    void link(Node *first, Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    //----------------------BASIC FUNCTIONS---------------------------//
    void print()
    {
        if (!length)
            return;

        for (Node *curr = head; curr; curr = curr->next)
        {
            std::cout << curr->data << '\t';
        }
        std::cout << '\n';
    }

    void insert_end(int value)
    {
        Node *add = new Node(value);
        if (!length)
        {
            head = tail = add;
        }
        else
        {
            link(tail, add);
            tail = add;
        }
        add_node(add);
        debug_verify_data_integrity();
    }

    void insert_front(int value)
    {
        Node *add = new Node(value);

        if (!length)
            head = tail = add;
        else
        {
            link(add, head);
            head = add;
        }
        add_node(add);
        debug_verify_data_integrity();
    }

    void embed_after(Node *before, int value)
    {
        Node *toadd = new Node(value);
        ++length;
        debug_add_node(toadd);

        Node *after = before->next;
        link(before, toadd);
        link(toadd, after);
    }

    void insert_sorted(int value)
    {
        if (!length || value <= head->data){
            insert_front(value);
            return ; 
        }
        if (tail->data <= value){
            insert_end(value);
            return ;
        }
        else
        {
            for (Node *curr = head; curr; curr = curr->next)
            {
                if (value <= curr->data)
                {
                    embed_after(curr->prev, value);
                    break;
                }
            }
        }
    }
};

#endif