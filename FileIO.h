#include "Delimiter.h"
#include <fstream>

//Class to read in source file and implement the stack and delimiter classes
template <class T>
class FileIO {
  public:
    FileIO();
    FileIO(string name);
    ~FileIO();
    void setFileName(string name);
    string getFileName();
    bool readInFile();

    //allocate more memory to lineCountValues
    int* allocateMoreMemory(int* curr, int currentSize);

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

//destructor
template <class T>
FileIO<T>::~FileIO(){
 //nothing gets deleted because no pointers are being created
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
    return true;
  }

  string currentLine = "";
  string delimiters = "";

  GenStack<T> *stack = new GenStack<T>(); //creates generic stack of size 1000 (default size)
  int stackSize = stack->getSize();
  int delimiterCount = 0; //keeps track of count as source file is being read

  //this array will keep track of the lines in the file that have delimiters
  int *lineCountValues = new int[delimiterCount];
  int tempLine = 0;
  int j = 0; //index of lineCountValues array

  //read in file and put all of the delimiters onto a string
  while (!inFS.eof()) {
    getline(inFS, currentLine);
    if (!inFS.fail()) {
      ++tempLine;
      //take in the delimiters found and put it into a string
      for (int i = 0; i < currentLine.size(); ++i) {
        char currentChar = currentLine[i];
        //need to check if more memory needs to get allocated or not before performing delimiter actions
        if (delimiterCount == (stackSize - 1)) {
          lineCountValues = allocateMoreMemory(lineCountValues, delimiterCount);
          stack = stack->allocateMoreMemory();
          stackSize = stack->getSize();
        }
        if (currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']' || currentChar == '(' || currentChar == ')' ) {
          delimiters += currentChar;
          ++delimiterCount;
          lineCountValues[j] = tempLine;
          ++j;
        }
      }
    }
  }

  inFS.close();

  //create the delimiter object after getting all of the necessary information
  Delimiter<T> *d = new Delimiter<T>(stack, delimiterCount, delimiters, lineCountValues);

  //run algorithm from delimiter class
  bool errorCheck = d->delimiterCheck();
  return errorCheck;
}

template <class T>
int* FileIO<T>::allocateMoreMemory(int* curr, int currentSize) {
  int newSize = currentSize * 2;
  int* newArray = new int[newSize];
  for (int i = 0; i < currentSize; ++i) {
    newArray[i] = curr[i];
    cout << newArray[i] << " ";
  }

  return newArray;
}
