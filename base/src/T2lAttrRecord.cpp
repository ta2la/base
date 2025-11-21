//
// Copyright (C) 2020 Petr Talla. [petr.talla@gmail.com]
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

#include "T2lAttrRecord.h"
#include <assert.h>

using namespace T2l;
using namespace std;

//=============================================================================
AttrRecord::AttrRecord()
{
    //assert(0); //obsolete
}

//=============================================================================
void AttrRecord::readArguments(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        string attri(argv[i]);
        string substr = attri.substr(0, 2);
        if (substr == "--") {
            string name = attri.substr(2, attri.length()-2);
            attrsAdd(Attr(name.c_str(), ""));
        }
        else {
            int count = attrsCount();
            if (count>0 && string(attrsGet(count-1).value()).empty()) {
                attrsGet(count-1) = Attr(attrsGet(count-1).name(), attri.c_str());
            }
            else {
                attrsAdd(Attr("", attri.c_str()));
            }
        }
    }
}

//=============================================================================
Attr* AttrRecord::attrsGet(const char* name, int index)
{
    string nameStr(name);

    for ( int i = 0; i < attrsCount(); i++ ) {
        Attr& attri = attrsGet(i);
        if (nameStr != attri.name()) continue;
        if (index == 0) return &attri;
        index--;
    }

    return nullptr;
}

//=============================================================================
const char* AttrRecord::getValue(const char* name, const char* implicit, int index)
{
    Attr* attr = attrsGet(name, index);
    if (attr == nullptr) return implicit;
    return attr->value();
}

//=============================================================================
double AttrRecord::getValue(const char* name, double implicit)
{
    string value = getValue(name);
    if (value.empty()) return implicit;

    return stod(value);
}

//=============================================================================
std::string AttrRecord::print()
{
    string result;

    for (int i = 0; i < attrsCount(); i++)
    {
        result += attrsGet(i).print();
        if ( i != attrsCount()-1) result += "\n";
    }

    return result;
}

//=============================================================================
