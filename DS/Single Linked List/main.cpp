#include <iostream>
#include "List.hpp"

using namespace std;
/*
    basic --> basic testing
    Easy --> Testing HW Easy functions
    Medium --> Testing HW medium functions
*/

void basic()
{
    List list;

    cout << "***************************\n";
    cout << "TEST 1:  Basic Functions\n\n";
    cout << "Insert Function\n";
    cout << "--------------------\n";
    list.insert_end(11);
    list.insert_end(12);
    list.insert_end(13);
    list.insert_end(14);
    list.print();
    cout << endl;
    cout << '\n';

    cout << "Does the list is empty ?? " << boolalpha << list.empty() << endl;
    cout << "------------------------------------------------\n";
    cout << "Insert Front the value 10" << endl;
    list.insert_front(10);
    list.print();

    cout << "current size of the list: " << list.list_size() << endl;
    cout << "Get the Nth Element --> ";
    cout << list.get_nth(1)->data << endl; // 10

    cout << "LETS Delete the first element in the list !!! " << endl;
    list.pop_front();
    list.print();

    cout << "LETS Delete the last element in the list !! " << endl;
    list.pop_back(); // 14 --> 11 12 13
    list.print();
    cout << "***************************\n";
}

void Easy()
{
    return;
}

void Medium()
{
    return;
}

int main()
{
    basic();

    return 0;
}