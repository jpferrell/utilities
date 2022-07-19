#include "BinaryFileReader.hh"

/**
 * Constructor. Opens input filename file in binary mode and determines the
 * endianness of the system. Sets the file pointer to the beginning of the file.
 *
 * ARGS:
 *   filename (std::string): Filename of binary file.
 */
Utilities::BinaryFileReader::BinaryFileReader(std::string filename) : m_filename{filename}
{
  m_file.open(filename, std::ios::binary);
  m_isBigEndian = determineEndianness();

  m_file.clear();
  m_file.seekg(std::ios::beg);
}

/**
 * Destructor. Make sure to close the file if it is still open.
 */
Utilities::BinaryFileReader::~BinaryFileReader()
{
  if (m_file.is_open()) {
    m_file.close();
  }
}

std::string Utilities::BinaryFileReader::getFilename()
{
  return m_filename;
}

/**
 * Determines the endianness of the system.
 * code based on https://stackoverflow.com/questions/12791864/c-program-to-check-little-vs-big-endian/12792301#12792301
 *
 * RETURNS
 *   false if little endian
 *   true if big endian
 */ 
bool Utilities::BinaryFileReader::determineEndianness()
{
  int n = 1;
  // If evaluates true is Little Endianness
  if(*(char *)&n == 1) {
    return false;
  } else {
    return true;
  }
}

/**
 * Specialized instance of the readFromFile method to read a single byte
 * from the binary file.
 */
template <>
unsigned char Utilities::BinaryFileReader::readFromFile<unsigned char>()
{
  char rByte;
  m_file.read(&rByte, 1);
  
  return rByte;
}

/**
 * Specialized instance of the readFromFile method to read two bytes from
 * the binary file.
 */
template <>
unsigned short int Utilities::BinaryFileReader::readFromFile<unsigned short int>()
{
  unsigned short int in, rByte;

  m_file.read(reinterpret_cast<char*>(&in), sizeof(in));

  if (!m_isBigEndian) {
    rByte = ((in & 0xFF00) >> 8) | ((in & 0x00FF) << 8);
  } else {
    rByte = in;
  }
  return rByte;
}

/**
 * Specialized instance of the readFromFile method to read four bytes from the 
 * binary file.
 */
template <>
unsigned int Utilities::BinaryFileReader::readFromFile<unsigned int>()
{
  unsigned int in, rByte;
  m_file.read(reinterpret_cast<char*>(&in), sizeof(rByte));

  if (!m_isBigEndian) {
    rByte = ((in & 0x000000FF) << 24) |
      ((in & 0x0000FF00) << 8) |
      ((in & 0x00FF0000) >> 8) |
      ((in & 0xFF000000) >> 24);
  } else {
    rByte = in;
  }

  return rByte;
}

/**
 * Returns string telling endianness of system. Used for debug purposes.
 */
std::string Utilities::BinaryFileReader::getEndianness()
{
  if (m_isBigEndian) {
    return "Big endian";
  } else {
    return "Little endian";
  }
}
