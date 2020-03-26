#include "Delimiter.h"

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

    if (m_currentChar == '{' || m_currentChar == '(' || m_currentChar == '[') {
      m_stack->push(m_currentChar);
    } else {
      stackChar = m_stack->pop();
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
      continue;
    }
  }
  cout << "Done!" << endl;
  return m_error;
}

template <class T>
void Delimiter<T>::printToConsole() {
  cout << "Error: Delimiter is " << m_currentChar << "but expected " << m_correctChar << endl;
  //cout << "Error at line " << m_lineError << ". Delimiter is " << m_currentChar << " but expected " << m_correctChar << endl;
}
