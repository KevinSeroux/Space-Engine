#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Engine.h"

class Logger
{
 public:
  Logger();
    void log(const std::string& message);
 private:
    std::ofstream _logFileStream;
    bool _isError;
};

#endif
