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

#include "T2lStringAscii.h"

#include <string>

namespace T2l
{

class AttrSTR;
class AttrNUM; ////

//====================================================================
class AttrBase {
//====================================================================
public:
//<ENUMS>
    enum Type{ STR, NUM, OLD };
//<CONSTRUCTION>
    AttrBase(  const StringAscii& name );
    virtual ~AttrBase(void) {}

    virtual AttrBase* clone() const = 0;
//<METHODS>
    virtual Type        type() = 0;
    StringAscii         name() const{ return name_;  }
    virtual std::string value()     { return "";     }

    virtual AttrSTR* getAsSTR()     { return nullptr; }
    virtual AttrNUM* getAsNUM()     { return nullptr; }
//====================================================================
protected:
//<OVERRIDES>
//<DATA>
    StringAscii name_;
//<INTERNALS>
//<FRIENDS>
};

} //T2l
