#include "FileIO.h"
#include <iostream>

int main(int argc, char**argv) {
    string filePath = "";
    if (argc > 1) {
      filePath = argv[1];
    }

    bool error = false;

    //ISSUE: I don't think I'm doing the template class stuff correctly, so we need to figure out how to fix this
    while (error != true) {
      string data = "";
      while (data != "char" || data != "int") {
        cout << "What data type would you like to use? Enter 'char' or 'int'." << endl;
        cin >> data;
        if (data == "char") {
          FileIO<char> *file = new FileIO<char>(filePath);
          error = file->readInFile();
          delete file;
          break;
        } else if (data == "int") {
          FileIO<int> *file = new FileIO<int>(filePath);
          error = file->readInFile();
          delete file;
          break;
        } else {
          cout << "Error. Input either the char or int data types." << endl;
        }
      }
      if (error == true) {
        break;
      } else {
        cout << "Enter a file path for another source code you want to check. " << endl;
        cin >> filePath;
      }
    }
  return 0;
}
