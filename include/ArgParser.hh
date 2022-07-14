#ifndef __ARGPARSER__HH__
#define __ARGPARSER__HH__

#include <iostream> // cout
#include <vector> // Vector class
#include <string> // substr, size

using ArgVector = std::vector<std::vector< std::string > >;
using StringVector = std::vector< std::string >;

namespace Utilities {
  class ArgParser {
  public:
    ArgParser(int, char**);
    ~ArgParser();
    ArgParser(const ArgParser&) = delete;

    ArgParser operator=(const ArgParser&) = delete;
    void printFlags() const;
    void printFlagArgs(std::string) const;
    void printArgParser() const;

    bool isFlagPresent(std::string) const;

    StringVector getFlagArguments(std::string) const;
  private:
    ArgVector argVect;

    void populateVector(int, char**);
    void populateArguments(int, char**, StringVector&, int);
  };

  std::ostream& operator<<(std::ostream &os, ArgParser &obj);
}

#endif //__ARGPARSER__HH__
