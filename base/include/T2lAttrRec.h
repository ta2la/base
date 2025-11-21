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

#include <T2lAttrBase.h>
#include <vector>

namespace T2l
{

//=============================================================================
class AttrRec
//=============================================================================
{
public:
//<CONSTRUCTION>
    AttrRec();
//<METHODS>
    void add(const AttrBase& attr) { attrs_.push_back(attr.clone()); }

    std::size_t count() { return attrs_.size(); }
    AttrBase* get(int index) { attrs_[index]; }

    AttrBase* get(const StringAscii& name,    int index = 0);
    AttrSTR*  getSTR(const StringAscii& name, int index = 0);
    AttrNUM*  getNUM(const StringAscii& name, int index = 0);
//=============================================================================
protected:
//<DATA>
    std::vector<AttrBase*> attrs_;
};

}
