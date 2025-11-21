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
#include "T2lStringAscii.h"
#include <string>

namespace T2l
{

//====================================================================
class AttrSTR : public AttrBase {
//====================================================================
public:
//<ENUMS>
//<CONSTRUCTION>
    AttrSTR( const StringAscii& name, const std::string& value );
    virtual ~AttrSTR(void) {}
//<METHODS>
//<OVERRIDES>
    std::string value()       override { return value_; }
    Type        type()        override { return STR;    }
    AttrBase*   clone() const override { return new AttrSTR(name(), value_); }
    AttrSTR*    getAsSTR()    override { return this; }
//====================================================================
protected:
//<DATA>
    std::string     value_;
//<INTERNALS>
//<FRIENDS>
};

} //T2l
