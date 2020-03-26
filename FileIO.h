#include "Delimiter.h"
#include <fstream>

//Class to read in source file and implement the stack and delimiter classes
template <class T>
class FileIO {
  public:
    FileIO();
    FileIO(string name);
    //no destructor here because we need it for the other classes
    void setFileName(string name);
    string getFileName();
    bool readInFile();
  private:
    string m_fileName;
    ifstream inFS;
};

//.cpp code needs to be in the same file since it's using a template class

//default constructor
template <class T>
FileIO<T>::FileIO(){
  m_fileName = "";
}

//overloaded constructor
template <class T>
FileIO<T>::FileIO(string name) {
  m_fileName = name;
}

//Setter method for file name
template <class T>
void FileIO<T>::setFileName(string name) {
  m_fileName = name;
}

//Getter method for file name
template <class T>
string FileIO<T>::getFileName() {
  return m_fileName;
}

//Method to read in file and get all of the necessary components to run algorithm
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

  //read in file and put all of the delimiters onto a string
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

  int j = 0; //index tracker for line count array
  while (!inFS.eof()) {
    getline(inFS, currentLine);
    if (!inFS.fail()) {
      ++tempLine;
      //take in the delimiters found and put it into a string
      for (int i = 0; i < currentLine.size(); ++i) {
        char currentChar = currentLine[i];
        if (currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']' || currentChar == '(' || currentChar == ')' ) {
          lineCountValues[j] = tempLine;
          ++j;
        }
      }
    }
  }

  inFS.close();

  //Create the stack and delimiter objects using all of the information from above
  GenStack<T> *stack = new GenStack<T>(delimiterCount);
  Delimiter<T>*d = new Delimiter<T>(stack, delimiterCount, delimiters, lineCountValues);

  //run algorithm from delimiter class
  bool errorCheck = d->delimiterCheck();
  return errorCheck;
}
