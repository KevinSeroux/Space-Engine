/*------------------------------------------------------------------------------
| Copyright (C) 2012 Seroux Kévin                                              |
|                                                                              |
| This program is free software; you can redistribute it and/or                |
| modify it under the terms of the GNU Lesser General Public                   |
| License as published by the Free Software Foundation; either                 |
| version 2.1 of the License, or (at your option) any later version.           |
|                                                                              |
| This program is distributed in the hope that it will be useful,              |
| but WITHOUT ANY WARRANTY; without even the implied warranty of               |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU             |
| Lesser General Public License for more details.                              |
|                                                                              |
| You should have received a copy of the GNU Lesser General Public             |
| License along with this program; if not, write to the Free Software          |
| Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA |
------------------------------------------------------------------------------*/

#include "Logger.h"
#include "Engine.h"

Logger::Logger()
{
    _isError = false;
    struct tm dateTime;
    //const std::string str = "Logs/log-" + dateTime.tm_yday + '.' + dateTime.tm_mon + (1900+dateTime.tm_year) + '-' + dateTime.tm_hour + '.' + dateTime.tm_min + '.' + Engine::getInstance()->getVarManager().convertToString(dateTime.tm_sec) + ".log";
    //_logFileStream.open(str.c_str());
    _logFileStream.open("log.log");
    if(!_logFileStream)
    {
	_isError = true;
	std::cout << "Failed to write log file" << std::endl;
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
