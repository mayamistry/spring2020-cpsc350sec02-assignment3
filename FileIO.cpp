#include "FileIO.h"

template <class T>
FileIO<T>::FileIO(){
  m_fileName = "";
}

template <class T>
FileIO<T>::FileIO(string name) {
  m_fileName = name;
}

template <class T>
void FileIO<T>::setFileName(string name) {
  m_fileName = name;
}

template <class T>
string FileIO<T>::getFileName() {
  return m_fileName;
}

template <class T>
bool FileIO<T>::readInFile() {
  cout << "Opening source file provided..." << endl;
  inFS.open(m_fileName);

  if (!inFS.is_open()) {
    cout << "Could not open file. Start program over." << endl;
    return false;
  }

  string currentLine = "";
  string delimiters = "";
  int lineCount = 0;
  int delimiterCount = 0;

  while (!inFS.eof()) {
    inFS >> currentLine;
    if (!inFS.fail()) {
      lineCount++;
      //take in the delimiters found and put it into a string
      for (int i = 0; i < currentLine.size(); ++i) {
        char currentChar = currentLine[i];
        if (currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']' || currentChar == '(' || currentChar == ')' ) {
          delimiters += currentChar;
          delimiterCount++;
        }
      }
    }
  }

  inFS.close();

  //need to fill in the array with the line values for source code
  inFS.open(m_fileName);

  //this array will keep track of the lines in the file that have delimiters
  int *lineCountValues = new int[delimiterCount];
  int tempLine = 0;

  while (!inFS.eof()) {
    inFS >> currentLine;
    if (!inFS.fail()) {
      ++tempLine;
      //take in the delimiters found and put it into a string
      for (int i = 0; i < currentLine.size(); ++i) {
        int j = 0; //index tracker for line count array
        char currentChar = currentLine[i];
        if (currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']' || currentChar == '(' || currentChar == ')' ) {
          lineCountValues[j] = tempLine;
          j++;
        }
      }
    }
  }

  inFS.close();

  GenStack<T> *stack = new GenStack<T>(delimiterCount);
  Delimiter<T>*d = new Delimiter<T>(stack, delimiterCount, delimiters, lineCountValues);

  bool errorCheck = d->delimiterCheck();
  return errorCheck;
}
