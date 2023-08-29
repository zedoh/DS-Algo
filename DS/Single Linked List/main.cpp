#include <iostream>
//#include "NoTail.hpp" // Linked List without tail or length !!
#include "List.hpp"

using namespace std;

void printLine(const string &text)
{
    cout << "\n__________________________________________________________\n";
    cout << text<<'\n';
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

    printLine("Let's REVERSE the list ");
    list.reverse(); // 77 66 12 11
    list.print();
    cout << '\n';

    printLine("Delete an Element that has the value 66");
    list.remove_value(66); // 77 , 12 , 11
    list.print();

    cout << "\nNo RTE !!" << endl;
}

void Easy()
{
    // Add your test code for Easy functions here
    List a;
    List b;
    a.insert_end(77);
    a.insert_end(12);
    a.insert_end(66);

    b.insert_end(77);
    b.insert_end(12);
    b.insert_end(11);
    cout << boolalpha << a.is_same(b) << '\n';
}

/*void Notail()
{
    NoTailList a;
    a.add_element(11);
    a.add_element(12);
    a.add_element(133);
    a.print();

    cout << "The tail of that list is : " << a.getTail()->data << '\n';
}
*/
//***********************************************************//

// Easy->Medium && Medium challanges tests go here .
void EasyToMedium()
{ 
    List a ; 
    a.insert_end(1) ; 
    a.insert_end(2) ; 
    a.insert_end(3) ; 
    a.insert_end(4) ; 
    a.insert_end(10) ; 
    printLine("Normal print") ; 
    a.print() ; 

    printLine("Swapping 2 pairs") ; 
    a.swap_pairs() ; 
    a.print() ; 
    a.swap_pairs() ; 

    printLine("Let's Reverse all this Data !! ") ; 
    a.reverse() ; 
    a.print() ;
    // cout << "\n\nLet's check for the addresses of the list !!\n";
    // a.debug_print_address() ; 
    a.reverse() ; 
    printLine("Deleting the value of 4") ; 
    a.delete_node_with_key(4) ; 
    a.print() ; 
    cout<<"\n" ; 

    printLine("Deleting the even positions in the list") ; 
    a.delete_even() ; 
    a.print() ; 


    // a.insert_sorted(6) ; 
    // a.insert_sorted(7) ; 
    // a.insert_sorted(11) ; 
    // a.print() ; 

}

void Medium(){
    List list ; 
    list.insert_end(1) ; 
    list.insert_end(2) ; 
    list.insert_end(3) ; 
    list.insert_end(3) ;
    list.insert_end(4) ; 
    list.insert_end(4) ; 
    list.insert_end(4) ; 
    list.insert_end(5) ; 
    list.insert_end(17) ; 
    list.insert_end(51) ; 

    printLine("Normal Print") ; 
    list.print() ; 

    printLine("Swapping the head and the tail") ; 
    list.swap_head_tail() ; 
    list.print() ; 


    printLine("Rotating the list")  ; 
    list.rotate_left(12) ; 
    list.print() ; 

    printLine("Removing duplicates") ;
    list.remove_duplicates_from_not_sorted() ;
    list.print();

    printLine("Adding some values to the list");
    list.insert_end(51) ; 
    list.insert_front(3) ; 
    list.print() ; 
    printLine("Remove the last occurance of the value 3 & 51") ; 
    list.RemoveLastOcc(3) ; 
    list.RemoveLastOcc(51) ; 
    list.print() ; 
}

void Medium2() {
    List list ; 
    list.insert_end(1) ; 
    list.insert_end(2) ; 
    list.insert_end(3) ; 
    list.insert_end(1) ; 
    list.insert_end(2) ; 
    list.insert_end(4) ; 
    list.insert_end(1) ; 
    list.insert_end(7) ; 
    list.insert_end(1) ; 
    list.insert_end(8) ; 
    
    printLine("Delete the last occur of the value 1") ; 
    list.RemoveLastOcc(1) ; 
    // printLine("Move back all the nodes with the value of 1:") ; 
    // list.MoveBack(1) 
    list.print() ; 

    printLine("Return the maximum number from the list") ; 
    cout<<list.max()<<'\n' ; 

}
int main()
{
    // basic();
    // cout<<"\n\n\nEASY HW TESTING\n" ;
    // Easy();
    // Notail();
    // EasyToMedium() ; 
    //Medium() ; 
    Medium2() ; 

    return 0;
}
