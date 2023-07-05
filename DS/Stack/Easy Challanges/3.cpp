#include<iostream>
#include<stack>
using namespace std ;

void fast(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr) ; 
}

int  reverse(int number){
    if(!number)return -1 ; 

    stack<int> st ;

    while (number)
        st.push(number % 10), number /= 10;

    int tens {1} ; 
    while (!st.empty())
    {
        number+=st.top()*tens ;
        tens*=10 ;  
        st.pop() ; 
    }
    
    return number; 
}

int main(){
    void fast() ; 
    cout<<reverse(1234)<<'\n'; 
    cout<<reverse(-1234)<<'\n'; 

    return 0 ; 
}