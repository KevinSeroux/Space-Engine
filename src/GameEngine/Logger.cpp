#include "Logger.h"

void Logger::displayMessage(const std::string& message)
{
    std::cout << "The application has encountered a problem :" << std::endl << std::endl << message << std::endl << std:: endl;
}
