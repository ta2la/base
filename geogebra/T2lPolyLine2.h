//
// Copyright (C) 2015 Petr Talla. [petr.talla@gmail.com]
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

#include "T2lPoint2Col.h"
#include "T2lLine2.h"

namespace T2l {

//=============================================================================
class PolyLine2 {
//=============================================================================
public:
//<CONSTRUCTION>
    PolyLine2(bool closed = false);
    ~PolyLine2() {}
//<NEIGHBOURS>
    Point2Col<double>& points() { return points_; }
//<DATA>
    bool closed() { return closed_; }
//<ITEMS>
    Point2F get(int index) { return points_.get(index); }
    int count() { return points_.count(); }
    int segmentCount() { return count()-1; }
    Line2 segmentGet(int index);
//<METHODS>
    void offset(PolyLine2& result, double offsetArg);
    Point2F offsetVertex(int index, double offset);
    Point2F getPoint(double parameter);
    double paramMax() { return closed() ? points().count()+1 : points().count(); }
    int vertex(double parameter);
    double paramAtRatio(double ratio); //0-1; 0-beg, 1-end
    double length();
//=============================================================================
protected:
//<DATA>
    Point2Col<double> points_;
    bool              closed_;
};

} // namespace t2l
