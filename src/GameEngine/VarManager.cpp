#include "VarManager.h"

template <class T>
std::string& VarManager::convertToString(const T& str)
{
    std::ostringstream oss;
    oss << str;
    return oss.str();
}
