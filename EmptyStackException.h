#include <iostream>
using namespace std;

//Exception class to see if stack is empty when popping off a stack
class EmptyStackException {
  public:
    EmptyStackException();
    EmptyStackException(string message);
    ~EmptyStackException();

    string getMessage();
  private:
    string m_message;
};
