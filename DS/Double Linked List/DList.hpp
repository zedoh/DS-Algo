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

    void set(Node *next, Node *prev)
    {
        this->next = next;
        this->prev = prev;
    }
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

    //-----------------------------Debuging TOOLS----------------------------------------------//
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

        if (node->prev == nullptr)
            std::cout << "X\t";
        else
            std::cout << node->prev->data << "\t";

        std::cout << " <= [" << node->data << "]\t => \t";

        if (node->next == nullptr)
            std::cout << "X\t";
        else
            std::cout << node->next->data << "\t";

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
        }
        else
        {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!head->prev);
            assert(!tail->next);
        }
        int len = 0;
        for (Node *cur = head; cur; cur = cur->next, len++)
        {
            if (len == length - 1) // make sure we end at tail
                assert(cur == tail);
        }

        assert(length == len);
        assert(length == (int)debug_data.size());

        len = 0;
        for (Node *cur = tail; cur; cur = cur->prev, len++)
        {
            if (len == length - 1) // make sure we end at head
                assert(cur == head);
        }
    }

    void delete_node(Node *node)
    {
        debug_remove_node(node);
        --length;
        delete node;
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

    void embed_after(Node *before, int value)
    {
        Node *toadd = new Node(value);
        ++length;
        debug_add_node(toadd);

        Node *after = before->next;
        link(before, toadd);
        link(toadd, after);
    }

    Node *delete_and_link(Node *curr){
        // Remove this node , but connect its neighbours
        Node *ret = curr->prev ; 
        link(curr->prev , curr->next) ; 
        delete_node(curr) ; 
        
        return ret ; 
    }

    int numberDuplicates(int value){ //How many times does a certain value exist in the list ?
        if(!length) return -1; 

        int count{0} ; 
        for(Node*curr= head ; curr ; curr=curr->next){
            if(curr->data == value){
                ++count ; 
            }
        }
        return count ;
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

    void insert_sorted(int value)
    {
        if (!length || value <= head->data)
        {
            insert_front(value);
            return;
        }
        if (tail->data <= value)
        {
            insert_end(value);
            return;
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

    void delete_front()
    {
        if (!length)
            return;

        Node *curr = head->next;
        delete_node(head);
        head = curr;

        // Checking the changes in the list
        if (head)
            head->prev = nullptr;
        else if (!length)
            head = tail = nullptr;

        debug_verify_data_integrity();
    }
    
    void delete_end(){
        if(!head) return ;
        Node *temp = tail->prev ; 
        delete_node(tail) ; 
        tail = temp;

        if (tail)
            tail->next = nullptr;
        else if (!length)
            head = tail = nullptr;
        debug_verify_data_integrity();
    }

    void delete_node_with_key(int value){
        if(!length) return ; 
        if(head->data == value) delete_front() ; 
        else{
            for(Node *curr =head ; curr ; curr=curr->next){
                if(curr->data == value){
                    curr = delete_and_link(curr) ; 
                    if(!curr->next){
                        tail = curr ; 
                    }
                    break ;
                }
            }
        }
        debug_verify_data_integrity();
    }

    void delete_all_nodes_with_key(int value){
        if(!length) return ; 
        int copies = numberDuplicates(value) ; //Number of copies for a certain value !! 

        for(int i = 0 ; i < copies ; ++i){ //O(N^2) Time , O(1) Space
            if (head->data == value)
            {
                delete_front();
            }
            else
            {
                for (Node *curr = head; curr; curr = curr->next)
                {
                    if (curr->data == value)
                    {
                        curr = delete_and_link(curr);
                        if (!curr->next)
                        {
                            tail = curr;
                        }
                        continue;
                    }
                }
            }
        }
        debug_verify_data_integrity();
    }


    void delete_even(){
        if(length<=1) return ; 

        for(Node *curr = head ; curr && curr->next ; curr = curr->next){
            delete_and_link(curr->next) ; 
            if(!curr->next){
                tail = curr ; 
                break ; 
            }
        }
        debug_verify_data_integrity() ; 
    }

    void delete_odd(){
        insert_front(-1) ; 
        delete_even() ; 
        delete_front() ; 
    }

    bool is_palindrome(){
        if(length<=1) return true  ; 
        int len {0} ; 
        for(Node * curr = head , *last = tail ; curr,last,len<=length/2 ; curr = curr->next , last = last->prev){
            if(curr->data != last->data){
                 return false ; 
            }
            ++len ; 
        }
        return true ; 
    }
};

#endif