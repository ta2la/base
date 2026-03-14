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
class Grid3 {
//=============================================================================
public:
// <CONSTRUCTION>
    Grid3( const Point3F& origin, const Vector3F& u, const Vector3F& v ) :
        origin_(origin),
        u_(u),
        v_(v) {}
    ~Grid3() = default;
// <METHODS>
    Point3F  getOrigin() const { return origin_; }
    Vector3F getU() const { return u_; }
    Vector3F getV() const { return v_; }

    Point3F  getPoint(const Point2F& uv) const {
        Vector3F u = u_; u.multiply(uv.x());
        Vector3F v = v_; v.multiply(uv.y());

        Point3F result = origin_;
        result.add(u);
        result.add(v);

        return result;
    }
//=============================================================================
    Point3F  origin_;
    Vector3F u_;
    Vector3F v_;
};

} // namespace t2l
