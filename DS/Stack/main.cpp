#include "STACK.hpp"
// #include"Dstack.hpp"
#include <iostream>
#include "Lstack.hpp"
#include<string>
#include<cctype>


using namespace std;

void msg(const string &line)
{
    cout << "\n----------------------------------------------------------------\n";
    cout << line;
    cout << "\n----------------------------------------------------------------\n";
}

void split()
{
    cout << "\n*******************************************************************\n";
}

void basic()
{
    Stack st(5);
    st.push(1);
    st.push(23);
    st.push(34);
    st.push(34);
    st.push(34);
    st.push(55);

    msg("Printing the stack");
    st.display();
    split();

    msg("Deleting an Element from the stack !!");
    st.pop();
    st.display();
    split();

    cout << st.peek();
}

/*void DoubleStack()
{
    Dstack st(10) ;
    st.push(1 , 1) ;
    st.push(1 , 2) ;
    st.push(1 , 3) ;
    st.push(1 , 4) ;
    st.push(1 , 5) ;
    st.push(2, 15);
    st.push(2, 14);
    st.push(2, 13);
    st.push(2, 12);
    st.push(2, 11);

    msg("First Stack!!!") ;
    st.display(1) ;
    split() ;


    msg("Second Stack!!!") ;
    st.display(2) ;
    split() ;

    msg("Poping the first element in the 2 stacks ") ;
    st.pop(1) ;
    st.pop(2) ;
    st.display(1) ;
    split() ;
    st.display(2) ;
    split() ;

    msg("Peeking the top element for both stacks!!") ;
    cout<<st.peek(1)<<'\n' ;
    cout<<st.peek(2)<<'\n' ;
    split() ;

}*/

void LinkedStack()
{
    Lstack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(33432);
    st.push(232);
    st.push(699);

    msg("Printing Linked List based Stack!!");
    st.display();
    split();

    msg("Deleting an Element from the stack");
    st.pop();
    st.display();
    split();

    cout << "What is the top value of this stack? : " << st.top() << '\n';
}

int main()
{
    // basic() ;
    // DoubleStack() ;
    LinkedStack();
    cout << "\nNO RTE\n";
}