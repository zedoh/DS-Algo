#include <iostream>
#include "List.hpp"

using namespace std;
/*
    basic --> basic testing
    Easy --> Testing HW Easy functions
    Medium --> Testing HW medium  to hard functions
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

    cout << "current size of the list: " << list.size() << endl;
    cout << "Get the Nth Element --> ";
    cout << list.get_nth(1)->data << endl; // 10

    cout << "LETS Delete the first element in the list !!! " << endl;
    list.pop_front();
    list.print();

    cout << "LETS Delete the last element in the list !! " << endl;
    list.pop_back(); // 14 --> 11 12 13
    list.print();
    cout << "***************************\n";

    cout << "Insert 55 at the front , 66 at the back\n";
    list.insert(list.size() + 1, 66);
    list.insert(1, 55);
    list.print();
    cout << "\n";

    cout << "The first element in the list is : ";
    cout << list.front() << endl;

    cout << "The last element in the list is : ";
    cout << list.back() << endl;

    cout<<"Delete the 3rd index: " ; //12
    list.erase(3) ; 
    list.print() ; 

    cout<<"\nReturn the 2nd element from the list: " ;
    cout<<list.value_from_end(2)<<endl ;  

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