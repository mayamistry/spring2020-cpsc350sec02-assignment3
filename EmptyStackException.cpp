#include "EmptyStackException.h"

//Default constructor
EmptyStackException::EmptyStackException() {
  m_message = "";
}

//Overloaded constructor
EmptyStackException::EmptyStackException(string message) {
  m_message = message;
}

//Destructor - no objects need to be deleted
EmptyStackException::~EmptyStackException() {
  //nothing happens here
}

//get method to get message if exception occurs
string EmptyStackException::getMessage() {
  return m_message;
}
