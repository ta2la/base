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
#pragma once

#include <T2lAttr.h>
#include <T2lListClever.h>

namespace T2l
{

//=============================================================================
class AttrRecord
//=============================================================================
{
public:
//<CONSTRUCTION>
    AttrRecord();

    void        readArguments(int argc, char *argv[]);
//<METHODS>
    void        attrsAdd(Attr attr) { attrs_.add(attr); }
    int         attrsCount() { return attrs_.count(); }
    Attr&       attrsGet(int index) { return attrs_.get(index); }
    Attr*       attrsGet(const char* name, int index = 0);
    const char* getValue(const char* name, const char* implicit = "", int index = 0);
    double      getValue(const char* name, double implicit);

    std::string print();
//=============================================================================
protected:
//<DATA>
    ListClever<Attr> attrs_;
};

}
