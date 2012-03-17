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

#ifndef VARMANAGER_H
#define VARMANAGER_H

#include <string>
#include <sstream>

class VarManager
{
 public:
    template<class T>
    const std::string& convertToString(const T& str)
    {
	_oss117 << str;
	return _oss117.str();
    }
 private:
    std::ostringstream _oss117;
};

#endif
