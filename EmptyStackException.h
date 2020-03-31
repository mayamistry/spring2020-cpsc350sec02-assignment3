#include <iostream>
using namespace std;

class EmptyStackException {
  public:
    EmptyStackException();
    EmptyStackException(string message);
    ~EmptyStackException();

    string getMessage();
  private:
    string m_message;
};
