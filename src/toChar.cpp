#include "toChar.h"
#include <string>

char toChar(std::string str)
{
    char c[str.size() + 1];
    str.copy(c, str.size() + 1);
    c[str.size()] = '\0';
    return *c;
}
