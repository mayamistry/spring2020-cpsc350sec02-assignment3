#include <iostream>
using namespace std;

class FullStackException {
  public:
    FullStackException();
    FullStackException(string message);
    ~FullStackException();

    string getMessage();
  private:
    string m_message;
};
