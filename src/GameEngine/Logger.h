#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

class Logger
{
 public:
    static void displayMessage(const std::string& message);
};

#endif
