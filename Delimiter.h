#include "GenStack.h"

//Class that performs the delimiter check algorithm using a stack and other necessary information
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

//.cpp code goes here since it's using a template class

//default constructor
template <class T>
Delimiter<T>::Delimiter() {
  m_stack = NULL;
  m_count = 0;
  m_delimiters = "";
  m_lineValues = NULL;
  m_lineError = 0;
  m_currentChar = '\0';
  m_correctChar = '\0';
  m_error = false;
}

//overloaded constructor
template <class T>
Delimiter<T>::Delimiter(GenStack<T> *s, int count, string d, int *lines) {
  m_stack = s;
  m_count = count;
  m_delimiters = d;
  m_lineValues = lines;
  m_lineError = 0;
  m_currentChar = '\0';
  m_correctChar = '\0';
  m_error = false;
}

//destructor
template <class T>
Delimiter<T>::~Delimiter() {
  delete m_stack;
  delete m_lineValues;
}

//algorithm method to check if there is an error
template <class T>
bool Delimiter<T>::delimiterCheck() {
  //iterate through the whole array of lines and each delimiter to check for ALL errors
  char stackChar = '\0';
  for (int i = 0; i < m_count; ++i) {
    m_currentChar = m_delimiters[i];
    cout << "Line " << m_lineValues[i] << ": " << m_currentChar << endl;

    //if it's an opening object, push onto the stack
    if (m_currentChar == '{' || m_currentChar == '(' || m_currentChar == '[') {
      m_stack->push(m_currentChar);
    } else {
      //if it's a closing object, then check if it's the right one
      stackChar = m_stack->pop();
      //if any of these are incorrect, it will print an error message and exit the algorithm
      switch (stackChar) {
        case '[':
          if (m_currentChar != ']') {
            m_lineError = m_lineValues[i];
            m_correctChar = ']';
            m_error = true;
            printToConsole();
          }
          break;
        case '(':
          if (m_currentChar != ')') {
            m_lineError = m_lineValues[i];
            m_correctChar = ')';
            m_error = true;
            printToConsole();
          }
          break;
        case '{':
          if (m_currentChar != '}') {
            m_lineError = m_lineValues[i];
            m_correctChar = '}';
            m_error = true;
            printToConsole();
          }
          break;
        default:
          break;
      }
      //if it's the right one, then keep going
      continue;
    }
  }
  cout << "Done!" << endl;
  return m_error;
}

//print method to print where and what the error is if it occurs in algorithm
template <class T>
void Delimiter<T>::printToConsole() {
  //cout << "Error: Delimiter is " << m_currentChar << "but expected " << m_correctChar << endl;
  cout << "Error at line " << m_lineError << ". Delimiter is " << m_currentChar << " but expected " << m_correctChar << endl;
}
