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

#include "T2lPoint2.h"
#include "T2lVector2.h"
#include "T2lBox2.h"

namespace T2l {
//
//   +----------------+                 A
//   | p3          p2 |                 |
//   |                | height          |
//   |                |                 | up
//   | p0          p1 |                 |
//   +----------------+                 |
// origin       width

//=============================================================================
class Rectangle2 {
//=============================================================================
public:
// <CONSTRUCTION>
    Rectangle2( const Point2F& origin = Point2F(0, 0), const Vector2F& width = Vector2F(1, 0), double height = 1);
    ~Rectangle2() {}
// <METHODS>
    Point2F point(int index) const;

    static Box2F boxFrom2pointsAndRatio( const Point2F& p0, const Point2F& p1, double wToH );
//=============================================================================
//<DATA>
    Point2F  origin_;
    Vector2F width_;
    double   height_;
//<INTERNALS>
    Vector2F up_() const;
};

} // namespace t2l
