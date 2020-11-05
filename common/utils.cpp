#include <common/utils.hpp>

std::string ReadFile(const std::string& filename)
{
unsigned int length;
char* buffer;

std::ifstream is;
is.open(filename.c_str(), std::ifstream::in);

// Check for bad paths
if (!is.is_open())
{
    LOG("Unable to open file: %s\n", filename.c_str());
    return "";
}

// get length of file:
is.seekg(0, std::ios::end);
length = static_cast<unsigned int>(is.tellg());
is.seekg(0, std::ios::beg);

// allocate memory
buffer = new char[length + 1];
memset(buffer, 0, length + 1);

// read data as a block:
is.read(buffer, length);
is.close();

// NB: specifying a length parameter will solve any null byte issues, even when
// reading arbitrary binary data.
std::string ret = std::string(buffer, length + 1);
delete[] buffer;

return ret;
}