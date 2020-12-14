//
// Copyright (C) 2016 Petr Talla. [petr.talla@gmail.com]
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

#include "T2lColumn.h"

#include <vector>

namespace T2l {

//=============================================================================
class ColumnF : public Column<double> {
//=============================================================================
public:
//<CONSTRUCTION>
    ColumnF( int size = 0 ) : Column<double>( size ) {}
    virtual ~ColumnF() {}
//<METHODS>
    static double diffSq(const ColumnF& c1, const ColumnF& c2);
    static double diffSqImportance(const ColumnF& c1, const ColumnF& c2, const ColumnF& importance);
//=============================================================================
//<OVERRIDES>
//<DATA>
};

} // namespace T2l
