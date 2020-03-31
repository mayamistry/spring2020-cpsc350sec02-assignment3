#include <iostream>
using namespace std;

//Exception to see if stack is full when trying to push
class FullStackException {
  public:
    FullStackException();
    FullStackException(string message);
    ~FullStackException();

    string getMessage();
  private:
    string m_message;
};
