#include "Logger.h"

Logger::Logger()
{
  _isError = false;
  struct tm dateTime;
  const std::string str = "Logs/log-" + dateTime.tm_yday + '.' + dateTime.tm_mon + (1900+dateTime.tm_year) + '-' + dateTime.tm_hour + '.' + dateTime.tm_min + '.' + Engine::getInstance().getVarManager().convertToString(dateTime.tm_sec) + ".log";
  _logFileStream.open(str.c_str());
  if(!_logFileStream)
    {
      _isError = true;
    }
}

void Logger::log(const std::string& message)
{
    std::cout << message << std::endl;
    if(!_isError)
      {
	_logFileStream << message << std::endl;
      }
}
