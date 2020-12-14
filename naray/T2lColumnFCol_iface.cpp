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
#include "T2lColumnFCol_iface.h"

using namespace T2l;

//=============================================================================
ColumnFCol_iface::~ColumnFCol_iface()
{
}

//=============================================================================
ColumnF ColumnFCol_iface::i_columnFCol_minmax_(bool max)
{
    if (i_columnFCol_count() == 0) return ColumnF(0);

    ColumnF result = i_columnFCol_get(0);

    for (int i = 1; i < i_columnFCol_count(); i++) {
        ColumnF actual = i_columnFCol_get(i);

        for (int ii = 0; ii < result.count(); ii++) {
            bool doit = false;

            if ( max ) {
                if ( result.get(ii) < actual.get(ii) ) doit = true;
            }
            else {
                if ( result.get(ii) > actual.get(ii) ) doit = true;
            }

            if ( doit ) {
                result.get(ii) = actual.get(ii);
            }
        }
    }

    return result;
}

//=============================================================================
