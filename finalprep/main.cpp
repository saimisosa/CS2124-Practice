#include <iostream>
using namespace std;


//Recursive function for a linked list clear function

struct Node {
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void clear(Node*& hp){
    if (hp == nullptr) return;
    clear(hp->next);
    delete hp;
    hp = nullptr;
}


//Try and Except (Exception Handling)

/*
try {

}
catch(int n) {} //integer
catch(const exception& ex) {}  //reference of type expection
catch(...) {} //cannot provide parameter because you dont really know what the issue will be

*/


//About multiple inheritence

/*
 if you're deriving from two different base methods and you're trying to call a display method,
 a method that both base classes have, that would be a case for ambiguity. c++ does not like that,
 so you either have to use the :: operator to specify which function that you want to be called,
 or you have to write your own display method so that ambiguity will not exist.
 */



//Assertions

// not intended for production. its merely a debugging tool.
//#define NDEBUG
//#include <cassert>
//assert(____)

//the what() method example

// the purpose of the what method is to return a c string (string literal, a string of characters)

class a {
    virtual const char* what() const noexcept {
        return "I am a what?";
    }
};

//Const iterator
/*
 if you're working on a const vector or a list, you need to disallow a reference return on a
 dereference operator

 ex. *iter = 17 couldnt work on a const vector/list

 HOWEVER, if you want to change something, you would use a regular iterator.
*/


int main() {
    return 0;
}
