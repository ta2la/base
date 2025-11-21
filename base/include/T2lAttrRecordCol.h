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

#include <T2lAttrRecord.h>

namespace T2l
{

//=============================================================================
class AttrRecordCol
//=============================================================================
{
public:
//<CONSTRUCTION>
    AttrRecordCol();
//<METHODS>
    void        recordAdd(const AttrRecord& record) { records_.add(record); }
    int         recordCount() { return records_.count(); }
    AttrRecord& recordGet(int index) { return records_.get(index); }
    AttrRecord* recordGet(const char* value, int index = 0, const char* attrName = "__type__");
    AttrRecord& recordLast() { return records_.last(); }

    void load(const char* input);
    std::string print();
//=============================================================================
protected:
//<DATA>
    ListClever<AttrRecord> records_;
};

}
