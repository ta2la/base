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

namespace T2l {

//=============================================================================
class Ray2 {
//=============================================================================
public:
// <CONSTRUCTION>
    Ray2( const Point2F& origin, const Vector2F& dir );
    Ray2( const Point2F& first,  const Point2F& second);
    ~Ray2() {}
// <METHODS>
    Point2F  getPoint(double parameter, double offset = 0.0) const ;
    Point2F  getPointDistance(double distance, double offset = 0.0);
    Vector2F getDir() const { return dir_; }

    static bool intersectParam(
            const Ray2& ray1,
            const Ray2& ray2,
            double& parameter,
            bool onlyExistence = false);
    double nearestParam( const Point2F& pt );
//=============================================================================
    Point2F  origin_;
    Vector2F dir_;
};

} // namespace t2l
