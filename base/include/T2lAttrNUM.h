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
#pragma once

#include "T2lAttrBase.h"
#include <vector>

namespace T2l
{

//====================================================================
class AttrNUM : public AttrBase {
//====================================================================
public:
//<ENUMS>
//<CONSTRUCTION>
    AttrNUM(const StringAscii& name, const std::string& value = "", const char* splitter = " ");
    AttrNUM(const StringAscii& name, double value);
    AttrNUM(const StringAscii& name, double v0, double v1 );
    AttrNUM(const StringAscii& name, double v0, double v1, double v2 );
    virtual ~AttrNUM(void) {}
//<ITEMS>
    void   add(double number) { numbers_.push_back(number); }
    int    count() { return numbers_.size(); }
    double get(int index = 0);
//<METHODS>
//<OVERRIDES>
    AttrBase* clone() const override;
//====================================================================
//<OVERRIDES>
    virtual std::string value();
    virtual Type type() { return NUM; }
    virtual AttrNUM* getAsNUM()     { return this; }
protected:
//<DATA>
    std::vector<double> numbers_;
//<INTERNALS>
//<FRIENDS>
};

} //T2l
