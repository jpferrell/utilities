#ifndef _BINARYFILEREADER_H_
#define _BINARYFILEREADER_H_

#include <string>
#include <fstream>
#include <iostream>
namespace Utilities {
  class BinaryFileReader{
  public:
    BinaryFileReader(std::string);
    ~BinaryFileReader();

    std::string getFilename();
    std::string getEndianness();

    template<class T>
    T readFromFile();
  
  private:
    bool determineEndianness();
  
    std::ifstream m_file;
    std::string m_filename;

    bool m_isBigEndian;
  };
}
#endif //_BINARYFILEREADER_H_
