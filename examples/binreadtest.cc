#include "BinaryFileReader.hh"
#include "ArgParser.hh"

using namespace Utilities;

int main(int argc, char **argv)
{
  ArgParser argParse(argc, argv);

  if (!argParse.isFlagPresent("f")) {
    std::cout << "Input file is missing\n";
    return -1;
  }

  StringVector fVect = argParse.getFlagArguments("f");
  std::string filename = fVect.at(0);
  
  BinaryFileReader bfr(filename);

  //unsigned short int in = bfr.readFromFile<unsigned short int>();
  unsigned char in1 = bfr.readFromFile<unsigned char>();
  std::cout << std::hex << (unsigned int)in1 << "\n";

  unsigned short int in2 = bfr.readFromFile<unsigned short int>();
  std::cout << std::hex << (unsigned int)in2 << "\n";
  
  unsigned int in3 = bfr.readFromFile<unsigned int>();
  std::cout << std::hex << (unsigned int)in3 << "\n";
  
  return 0;
}
