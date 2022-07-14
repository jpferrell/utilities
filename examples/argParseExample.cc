#include <iostream>
#include "ArgParser.hh"
#include "FileOps.hh"

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
  StringVector fileVec = argParse.getFlagArguments("f");
  cout << FileOps::getFilenameExtension(fileVec.at(0)) << "\n";
  
  return 0;
}
