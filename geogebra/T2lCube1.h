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

#include "T2lPoint3.h"

#include <utility>

namespace T2l {

class Ray3;

//=============================================================================
class Cube1 {

//=============================================================================
public:
// <CONSTRUCTION>
    Cube1(const Point3I& p3 );
    ~Cube1() {}
// <METHODS>
    Point3I& point() { return point_; }
    Point3F pointLower() const { return Point3F(
            static_cast<double>(point_.x()),
            static_cast<double>(point_.y()),
            static_cast<double>(point_.z()) );
    }
    static int         pointCount() { return 8; }
    Point3F            pointGet(int index);
    static int         verticeCount() { return 12; }
    std::pair<Point3F, Point3F> verticeGet(int index);
    static int         faceCount() { return 6; }
    std::array<int, 4> faceIndexes(int index);

    bool isInside(const Point3F& point);

    Point3F pointDelta(const Point3F& delta) const { return Point3F(
            static_cast<double>(point_.x())+delta.x(),
            static_cast<double>(point_.y())+delta.y(),
            static_cast<double>(point_.z())+delta.z() );
    }

    std::pair<int, double> nearestFace(const Ray3& ray);
//=============================================================================
protected:

//<DATA>
    Point3I point_;

    friend class Cmd_draw_cube1;
};

} // namespace t2l
