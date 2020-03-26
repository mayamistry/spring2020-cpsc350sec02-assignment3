#include "Delimiter.h"
#include <fstream>

template <class T>
class FileIO {
  public:
    FileIO();
    FileIO(string name);
    void setFileName(string name);
    string getFileName();
    bool readInFile();
  private:
    string m_fileName;
    ifstream inFS;
};
