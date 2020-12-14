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

#include "T2lColumnF.h"

namespace T2l {

//=============================================================================
class ColumnFCol_iface {
//=============================================================================
public:
//<CONSTRUCTION>
    ColumnFCol_iface() {}
    virtual ~ColumnFCol_iface();
//<METHODS>
    virtual int     i_columnFCol_count() = 0;
    virtual ColumnF i_columnFCol_get(int index) = 0;

    ColumnF i_columnFCol_minima() { return i_columnFCol_minmax_(false); }
    ColumnF i_columnFCol_maxima() { return i_columnFCol_minmax_(true); }
//=============================================================================
//<OVERRIDES>
//<DATA>
//<INTERNALS>
    ColumnF i_columnFCol_minmax_(bool max);
};

} // namespace T2l
