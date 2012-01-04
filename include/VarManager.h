#include <string>
#include <sstream>

class VarManager
{
 public:
    template <class T>
    static std::string& convertToString(const T& str);
};
