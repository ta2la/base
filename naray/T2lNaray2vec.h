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

#include "T2lNaray2.h"
#include "T2lIntervalF.h"
#include "T2lColumn.h"
#include "T2lColumnF.h"

#include "T2lPoint2.h"

#include <vector>

namespace T2l {

//=============================================================================
class Naray2vec : public Naray2<ColumnF> {
//=============================================================================
public:
//<CONSTRUCTION>
    Naray2vec( int d0, int d1 );
    virtual ~Naray2vec() {}
    void valsFromSet(const ColumnF& from) { valsFrom_ = from; }
    void valsToSet(const ColumnF& to)   { valsTo_   = to; }

    void initializeRandom(const ColumnF min, const ColumnF max);
//<METHODS>
    Point2I calculateBmatch(const ColumnF& c);
    Point2I calculateBmatch(const ColumnF& cc, const ColumnF& minima, const ColumnF& maxima, const ColumnF& importance);
    static double calculateDistance(const Point2I& p0, const Point2I& p1);

    ColumnF& valsFrom() { return valsFrom_; }
    ColumnF& valsTo()   { return valsTo_; }

    static double normalize(double value, double range, double minima, double maxima);
    static ColumnF normalize(const ColumnF& column, double range, const ColumnF& minima, const ColumnF& maxima);
//=============================================================================
//<OVERRIDES>
//<DATA>
    ColumnF valsFrom_;
    ColumnF valsTo_;
};

} // namespace T2l
