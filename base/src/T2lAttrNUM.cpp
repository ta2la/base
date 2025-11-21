//
// Copyright (C) 2018 Petr Talla. [petr.talla@gmail.com]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=============================================================================
#include "T2lAttrNUM.h"
#include <sstream>

using namespace T2l;
using namespace std;

//====================================================================
AttrNUM::AttrNUM(  const StringAscii& name, const std::string& value, const char* splitter ) :
    AttrBase(name)
{
    std::istringstream stream(value);
    std::vector<std::string> values;
    std::string substring;

    while (std::getline(stream, substring, ':')) {
       values.push_back(substring);
    }

    for ( int i = 0; i < values.size(); i++ ) {
        string& numstr = values.at(i);
        if (numstr.empty()) continue;
        add( std::stof(numstr) );
    }
}

//====================================================================
AttrNUM::AttrNUM(  const std::string& name, double value ) :
    AttrBase(name)
{
    add(value);
}

//====================================================================
AttrNUM::AttrNUM(const StringAscii& name, double v0, double v1 ) :
    AttrBase(name)
{
    add(v0);
    add(v1);
}

//====================================================================
AttrNUM::AttrNUM(const StringAscii& name, double v0, double v1, double v2 ) :
    AttrBase(name)
{
    add(v0);
    add(v1);
    add(v2);
}

//====================================================================
AttrBase* AttrNUM::clone() const
{
    AttrNUM* result = new AttrNUM(name());
    result->numbers_ = numbers_;
    return result;
}

//====================================================================
double AttrNUM::get(int index)
{
    if (index < 0) return 0;
    if (index >= count()) return 0;
    return numbers_.at(index);
}

//====================================================================
string AttrNUM::value()
{
    stringstream ss;
    for (int i = 0; i < count(); i++) {
        if (i != 0) ss << " ";
        ss << get(i);
    }

    return ss.str();
}

//====================================================================
