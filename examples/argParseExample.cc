#include <iostream>
#include "ArgParser.hh"

using namespace Utilities;
using namespace std;
int main(int argc, char **argv)
{
  ArgParser argParse(argc, argv);
  argParse.printFlags();
  argParse.printFlagArgs("f");
  cout << "Is flag f present? " << argParse.isFlagPresent("f") << "\n";
  //argParse.printArgParser();
  cout << argParse;
  
  return 0;
}
