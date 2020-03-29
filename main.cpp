#include "FileIO.h"
#include <iostream>

//Driver to implement assignment 3
int main(int argc, char**argv) {
    string filePath = "";
    if (argc > 1) {
      filePath = argv[1];
    }

    //boolean variable to check if the program should exit or not (if source code has an error, it will exit)
    bool error = false;

    while (error != true) {
      //instantiating the FileIO object to be of a type char (not  a template anymore)
      FileIO<char> *file = new FileIO<char>(filePath);
      error = file->readInFile();
      delete file;
      if (error == true) {
        break;
      } else {
        //if the program didn't have errors, the user can check another file
        cout << "Your file was completely correct! Enter a file path for another source code you want to check. If you want to quit, enter 'exit'." << endl;
        cin >> filePath;
        if (filePath == "exit") {
          break;
        }
      }
    }
  return 0;
}
