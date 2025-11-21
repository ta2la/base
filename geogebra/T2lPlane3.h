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
#include "T2lPoint2.h"

namespace T2l {

//=============================================================================
class Plane3 {
//=============================================================================
public:
// <CONSTRUCTION>
    Plane3( const Point3F& origin, const Vector3F& normal );
    Plane3( const Point3F& p0, const Point3F& p1, const Point3F& p2);
    ~Plane3() {}
// <METHODS>
    Point3F  getOrigin() const { return origin_; }
    Vector3F getNormal() const { return normal_; }
    Vector3F getU() const;
    Vector3F getV() const;
    Point3F  getPoint(const Point2F& uv, double d = 0) const ;

    Point2F uv(const Point3F& pt) const;
    double distance(const Point3F& pt) const { //oriented distance, has negative values
        return Vector3F::getDotProduct(Vector3F(origin_, pt), normal_); }

    Point3F projectPerpend(const Point3F& pt) {
        return Point3F(pt).add(Vector3F(normal_).multiply(-distance(pt))); }
//=============================================================================
    void calculateUV_() const;

    Point3F  origin_;
    Vector3F normal_;   //normalized
                        //right hand rule for top
    mutable Vector3F u_;
    mutable Vector3F v_;
};

} // namespace t2l
