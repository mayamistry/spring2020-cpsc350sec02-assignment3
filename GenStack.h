#include <iostream>
using namespace std;

template <class T>
class GenStack {
  public:
    GenStack(); //default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    //core functions
    void push(T data); //inserts a new elements into the stack --> pre-incrementation
    T pop(); //removes and returns the last element of the stack
    //POP DOES NOT REMOVE, IT JUST CHANGES THE POINTER FOR TOP SOMEWHERE
    //post incrementation

    //aux functions/helper functions
    T peek(); //returns the top element in the stack
    bool isEmpty();
    bool isFull();

    int top; //index of the top element --> used as a pointer
    int mSize;

    T *myArray; //this is a pointer to an array, memory address of the first block
    //every element is one byte over
};
