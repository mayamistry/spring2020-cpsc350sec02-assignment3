#include "FullStackException.h"
#include "EmptyStackException.h"

template <class T>
class GenStack {
  public:
    GenStack(); //default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    //core functions
    void push(T data) throw (FullStackException); //inserts a new elements into the stack --> pre-incrementation
    T pop() throw (EmptyStackException); //removes and returns the last element of the stack
    //POP DOES NOT REMOVE, IT JUST CHANGES THE POINTER FOR TOP SOMEWHERE
    //post incrementation

    //aux functions/helper functions
    T peek(); //returns the top element in the stack
    bool isEmpty();
    bool isFull();

    int getSize();
    GenStack* allocateMoreMemory();

    int top; //index of the top element --> used as a pointer
    int mSize;

    T *myArray; //this is a pointer to an array, memory address of the first block
    //every element is one byte over
};

template <class T>
GenStack<T>::GenStack() {
  myArray = new T[1000];
  mSize = 1000;
  top = -1; // -1 turnd into the 0
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize) {
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1; //could do 0 or -1
}

//destructor
template <class T>
GenStack<T>::~GenStack() {
  delete myArray;
}

template <class T>
void GenStack<T>::push(T data) throw (FullStackException) {
  //first check if this is full before attempting to insert
  if (isFull()) {
    throw FullStackException("FullStackException: stack is already full");
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop() throw (EmptyStackException) {
  //check array is empty before removing
  //USE POINTER AND NOT A .
  if (isEmpty()) {
    throw EmptyStackException("EmptyStackException: stack is empty already");
  }
  return myArray[top--];
}

template <class T>
T GenStack<T>::peek() {
  return myArray[top];
}

template <class T>
bool GenStack<T>::isEmpty() {
  return (top == -1); //if statement within the return statement
}

template <class T>
bool GenStack<T>::isFull() {
  return (top == mSize - 1);
}

template <class T>
int GenStack<T>::getSize() {
  return mSize;
}

template <class T>
GenStack<T>* GenStack<T>::allocateMoreMemory() {
  int newSize = mSize * 2;
  GenStack<T> *newStack = new GenStack<T>(newSize);
  return newStack;
}
