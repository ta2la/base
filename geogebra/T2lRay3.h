//
// Copyright (C) 2025 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lVector3.h"

#include <optional>

namespace T2l {

class Plane3;

//=============================================================================
class Ray3 {
//=============================================================================
public:
// <CONSTRUCTION>
    Ray3( const Point3F& origin, const Vector3F& dir );
    Ray3( const Point3F& first,  const Point3F& second);
    ~Ray3() {}
// <METHODS>
    Point3F  getPoint(double parameter) const ;
    //Point3F  getPointDistance(double distance, double offset = 0.0);
    Vector3F getDir() const { return dir_; }

    //double nearestParam( const Point2F& pt );
    std::optional<Point3F> getIntersect(const Plane3& plane) const;

//=============================================================================
    Point3F  origin_;
    Vector3F dir_;
};

} // namespace t2l
