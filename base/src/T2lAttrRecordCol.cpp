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
#include "T2lAttrRecordCol.h"

#include <sstream>
#include <iostream>
#include <assert.h>

using namespace T2l;
using namespace std;

//=============================================================================
AttrRecordCol::AttrRecordCol()
{
    assert(0); //obsolete
}

//=============================================================================
AttrRecord* AttrRecordCol::recordGet(const char* value, int index, const char* attrName)
{
    string attrStr(value);

    for ( int i = 0; i < records_.count(); i++) {
        AttrRecord& recordi = records_.get(i);
        Attr* attrType = recordi.attrsGet(attrName);
        if (attrType == nullptr) continue;
        if (attrType->value() != value) continue;

        if (index == 0) {
            return &recordi;
        }
        else {
            index--;
        }
    }

    return nullptr;
}

//=============================================================================
void AttrRecordCol::load(const char* input)
{
    stringstream ss(input);
    string       line;
    bool         interupted=true;

    while (getline(ss, line, '\n')) {
        if (line.find(":") == string::npos) {
            interupted = true;
        }
        else {
            if (interupted == true) {
                records_.add(AttrRecord());
                interupted = false;
            }

            Attr attr = Attr::read(line.c_str());
            AttrRecord& last = recordLast();
            last.attrsAdd(attr);
        }
    }
}

//=============================================================================
string AttrRecordCol::print()
{
    string result;

    for (int i = 0; i < recordCount(); i++) {
        result += recordGet(i).print();
        if ( i >= recordCount()-1) continue;
        result += "\n\n";
    }

    return result;
}

//=============================================================================


