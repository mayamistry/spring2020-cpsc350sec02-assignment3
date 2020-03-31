#include "FullStackException.h"

FullStackException::FullStackException() {
  m_message = "";
}

FullStackException::FullStackException(string message) {
  m_message = message;
}

FullStackException::~FullStackException() {
  //nothing happens here
}

string FullStackException::getMessage() {
  return m_message;
}
