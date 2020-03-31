#include "EmptyStackException.h"

EmptyStackException::EmptyStackException() {
  m_message = "";
}

EmptyStackException::EmptyStackException(string message) {
  m_message = message;
}

EmptyStackException::~EmptyStackException() {
  //nothing happens here
}

string EmptyStackException::getMessage() {
  return m_message;
}
