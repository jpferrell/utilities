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

    void printFlags() const;
    void printFlagArgs(std::string) const;
    void printArgParser() const;
  private:
    ArgVector argVect;

    void populateVector(int, char**);
    void populateArguments(int, char**, StringVector&, int);
  };

  std::ostream& operator<<(std::ostream &os, ArgParser &obj);
}
