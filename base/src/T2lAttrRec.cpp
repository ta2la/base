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

#include "T2lAttrRec.h"

using namespace T2l;
using namespace std;

//=============================================================================
AttrRec::AttrRec()
{
}

//=============================================================================
AttrBase* AttrRec::get(const StringAscii& name, int index)
{
    for(size_t i = 0; i < count(); i++) {
        AttrBase* result = get(i);
        if (result->name()!=name) continue;
        if (index == 0) return result;
        index--;
    }

    return nullptr;
}

//=============================================================================
AttrSTR* AttrRec::getSTR(const StringAscii& name, int index)
{
    AttrBase* result = get(name, index);
    if (result == nullptr) return nullptr;
    return result->getAsSTR();
}

//=============================================================================
AttrNUM* AttrRec::getNUM(const StringAscii& name, int index)
{
    AttrBase* result = get(name, index);
    if (result == nullptr) return nullptr;
    return result->getAsNUM();
}

//=============================================================================
