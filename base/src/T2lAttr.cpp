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

#include "T2lAttr.h"

using namespace T2l;
using namespace std;

//=============================================================================
Attr::Attr(const char* name, const char* value) :
    name_(name),
    value_(value)
{
}

//=============================================================================
Attr Attr::read(const char* nameValue, const char* delimiter)
{
    string nv(nameValue);

    const size_t last_slash_idx = nv.find(delimiter);
    string name  = nv.substr(0, last_slash_idx);
    string value = nv.substr(last_slash_idx+1);

    int beg = 0;
    int end = value.length()-1;

    for(int i = 0; i<value.length(); i++) {
        if (isspace(value[i])) {
            beg++;
        }
        else {
            break;
        }
    }

    for(int i = value.length(); i>=0; i--) {
        if (isspace(value[i])) {
            end--;
        }
        else {
            break;
        }
    }

    value = value.substr(beg, end);

    return Attr(name.c_str(), value.c_str());
}

//=============================================================================
