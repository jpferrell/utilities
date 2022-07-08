#include "ArgParser.hh"

using namespace Utilities;

int main(int argc, char **argv)
{
  ArgParser argParse(argc, argv);
  argParse.printFlags();
  argParse.printFlagArgs("f");
  std::cout << argParse << "\n";
  
  return 0;
}
