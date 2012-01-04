#ifndef VARMANAGER_H
#define VARMANAGER_H

#include <string>
#include <sstream>

class VarManager
{
 public:
    template<class T>
    static const std::string& convertToString(const T& str)
    {
	std::ostringstream oss;
	oss << str;
	return oss.str();
    }
};

#endif
