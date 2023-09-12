#include "trie.hpp"



int main() {

    trie t;
    t.Insert("hello");
    t.Insert("zeyad");
    t.Insert("welcome");
    t.Insert("to");
    t.Insert("the");
    t.Insert("system");
    t.Insert("loading");
    t.Insert("information");

    std::cout << std::boolalpha << t.word_exist("zello") << '\n';
    std::cout << std::boolalpha << t.word_exist("hello") << '\n';
    std::cout << std::boolalpha << t.word_exist("TO") << '\n';
    std::cout << std::boolalpha << t.word_exist("looding") << '\n'; 

    return 0;
}