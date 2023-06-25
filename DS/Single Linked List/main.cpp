#include <iostream>
#include "List.hpp"

using namespace std;

void printLine(const string &text)
{
    cout << "***********************************************************\n";
    cout << text << '\n';
    cout << "***********************************************************\n";
}

void basic()
{
    List list;

    printLine("TEST 1: Basic Functions");

    cout << "Insert Function\n";
    cout << "--------------------\n";
    list.insert_end(11);
    list.insert_end(12);
    list.insert_end(13);
    list.insert_end(14);
    list.print();
    cout << '\n';

    cout << "The size of the list is: " << list.size() << endl;
    cout << "Is the list empty? " << boolalpha << list.empty() << endl;

    printLine("Insert Front the value 10");
    list.insert_front(10);
    list.print();
    cout << "The size of the list is: " << list.size() << endl;
    cout << "\n";

    printLine("Get the Nth Element (the first element): ");
    cout << list.get_nth(1)->data << endl;
    cout << "\n";

    printLine("Let's Delete the first element in the list!! ");
    list.pop_front();
    list.print();
    cout << "The size of the list is: " << list.size() << endl;
    cout << "Let's delete the last element in the list!" << endl;
    list.pop_back();
    list.print();
    cout << "The size of the list is: " << list.size() << endl;
    cout << "\n";

    printLine("Insert 66 at the back then, 77 at the back");
    list.insert(3, 66);
    list.insert(list.size(), 77);
    list.print();
    cout << "The size of the list is: " << list.size() << endl;
    cout << "The first element in the list is: " << list.front() << endl;
    cout << "The last element in the list is: " << list.back() << endl;

    cout << "\n";
    printLine("Delete the 3rd index from the list:");
    list.erase(3);
    list.print();
    cout << "The size of the list is: " << list.size() << endl;
    cout << '\n';

    printLine("Return the 2nd element from the end of the list: ");
    cout << list.value_from_end(2) << endl;
    printLine("Return the 3rd element from the end of the list: ");
    cout << list.value_from_end(3) << endl;
    cout << "\n";

    printLine("Let's REVERSE the list ") ; 
    list.reverse() ; // 77 66 12 11
    list.print() ;
    cout << '\n';


    printLine("Delete an Element that has the value 66") ; 
    list.remove_value(66) ; // 77 , 12 , 11 
    list.print() ; 
}

void Easy()
{
    // Add your test code for Easy functions here
}

void Medium()
{
    // Add your test code for Medium to Hard functions here
}

int main()
{
    basic();

    return 0;
}
