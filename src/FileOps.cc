#include "FileOps.hh"

std::string Utilities::FileOps::getFilenameExtension(std::string filename)
{
  std::string s;
  auto const pos = filename.find_last_of('.');
  if (pos != std::string::npos) { 
  s = filename.substr(pos+1);
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  } else {
    s = "";
  }

  return s;
}
