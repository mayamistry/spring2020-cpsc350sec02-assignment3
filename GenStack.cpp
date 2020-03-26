#include "GenStack.h"

//default constructor
template <class T>
GenStack<T>::GenStack() {
  myArray = new char[128];
  mSize = 128;
  top = -1; // -1 turnd into the 0
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize) {
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1; //could do 0 or -1
}

//destructor
template <class T>
GenStack<T>::~GenStack() {
  delete myArray;
}

template <class T>
void GenStack<T>::push(T data) {
  //first check if this is full before attempting to insert
  if (isFull()) {
    cout << "Exception: stack is already full." << endl;
    return;
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop() {
  //check array is empty before removing
  //USE POINTER AND NOT A .
  if (isEmpty()) {
    cout << "Exception: stack is already empty." << endl;
    return '\0';
  } else {
    return myArray[top--];
  }
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
