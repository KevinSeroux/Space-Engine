#ifndef VARMANAGER_H
#define VARMANAGER_H

#include <string>
#include <sstream>

class VarManager
{
 public:
    template<class T>
    const std::string& convertToString(const T& str) const
    {
	std::ostringstream oss;
	oss << str;
	return oss.str();
    }
};

#endif
