#include "GenStack.h"

template <class T>
class Delimiter {
  public:
    Delimiter();
    Delimiter(GenStack<T> *s, int count, string d, int *lines);
    ~Delimiter();
    bool delimiterCheck();
    //helper method
    void printToConsole();
  private:
    GenStack<T>* m_stack;
    int m_count;
    string m_delimiters;
    int* m_lineValues;

    //for error purposes
    bool m_error;
    int m_lineError;
    char m_currentChar; //what the delimiter is
    char m_correctChar; //what the delimiter should be
};
