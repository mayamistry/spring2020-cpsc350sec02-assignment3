#include "FullStackException.h"

//Default constructor
FullStackException::FullStackException() {
  m_message = "";
}

//Overloaded constructor
FullStackException::FullStackException(string message) {
  m_message = message;
}

//Destructor - no pointers need to be deleted
FullStackException::~FullStackException() {
  //nothing happens here
}

//get method to get message of exception
string FullStackException::getMessage() {
  return m_message;
}
