#include "ArgParser.hh"

Utilities::ArgParser::ArgParser(int argc, char **argv)
{
  populateVector(argc, argv);
}

Utilities::ArgParser::~ArgParser()
{

}

void Utilities::ArgParser::populateVector(int argc, char **argv)
{
  for (int i = 1; i < argc; i++) { // skip first argument as it is just .exe
    std::string str(argv[i]);
    int j = 0;
    while(str.at(j) == '-') {
      j++;
    }
    if (j > 0) {
      StringVector tmpVect;
      if (j == 2) {
	tmpVect.push_back(str.substr(j));
	populateArguments(argc, argv, tmpVect, i);
	argVect.push_back(tmpVect);
      } else if (j == 1) {
	// if there is more than one character in a single '-' flag, separate
	// out the characters as separate flags
	// ie -rf will be two separate entries in the flagVect, one r, one f
	if (str.size() > 1) {
	  for (int idx = 0; idx < str.size()-1; idx++) {
	    tmpVect.push_back(str.substr(j+idx, 1));
	    populateArguments(argc, argv, tmpVect, i);
	    argVect.push_back(tmpVect);
	    tmpVect.clear();
	  }
	  
	} else {
	  tmpVect.push_back(str.substr(j, 1));
	  populateArguments(argc, argv, tmpVect, i);
	  argVect.push_back(tmpVect);
	}
      }
    }
  }
}

void Utilities::ArgParser::printFlags() const
{
  std::cout << "FLAGS: ";
  for (int i = 0; i < argVect.size(); i++) {
    std::cout << argVect.at(i).at(0) << "\t";
  }
  std::cout << "\n";
}

void Utilities::ArgParser::printFlagArgs(std::string flag) const
{
  for (int i = 0; i < argVect.size(); i++) {
    if (argVect.at(i).at(0).compare(flag) == 0) {
      std::cout << "ARGUMENTS: ";
      for (int j = 1; j < argVect.at(i).size(); j++) {
	std::cout << argVect.at(i).at(j) << "\t";
      }
      std::cout << "\n";
    }
  }
}

void Utilities::ArgParser::populateArguments(int argc, char **argv, StringVector &sVect, int idx)
{
  int i = idx+1;
  while ( i < argc && argv[i][0] != '-') {
    std::string tmpStr(argv[i]);
    sVect.push_back(tmpStr);
    i++;
  }
}

void Utilities::ArgParser::printArgParser() const
{
  for (int i = 0; i < argVect.size(); i++) {
    std::cout << "FLAG: " << argVect.at(i).at(0) << "\n";
    std::cout << "\tARGS: ";
    for (int j = 1; j < argVect.at(i).size(); j++) {
      std::cout << argVect.at(i).at(j) << "\t";
    }
    std::cout << "\n";
  }
}

std::ostream& Utilities::operator<<(std::ostream &os, Utilities::ArgParser &obj)
{
  return os;
}
