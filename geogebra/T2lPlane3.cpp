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
#include "T2lPlane3.h"

using namespace T2l;

//=============================================================================
Plane3::Plane3( const Point3F& origin, const Vector3F& normal ) :
    origin_(origin),
    normal_(normal),
    u_(Vector3F()),
    v_(Vector3F())
{
    normal_.setLength(1.0);
}

//=============================================================================
Plane3::Plane3( const Point3F& p0, const Point3F& p1, const Point3F& p2) :
    origin_(p0)
{
    Vector3F v1(p0,p1);
    Vector3F v2(p0,p2);

    normal_ = Vector3F::crossProduct(v1, v2).setLength(1.0);
}

//=============================================================================
Vector3F Plane3::getU() const
{
    if (u_.isZero()) calculateUV_();
    return u_;
}

//=============================================================================
Vector3F Plane3::getV() const
{
    if (v_.isZero()) calculateUV_();
    return v_;
}

//=============================================================================
void Plane3::calculateUV_() const
{
    if (fabs(normal_.x()) > fabs(normal_.z()))
        u_ = Vector3F(-normal_.y(), normal_.x(), 0.0f);
    else
        u_ = Vector3F(0.0f, -normal_.z(), normal_.y());

    u_.setLength(1.0);
    v_ = Vector3F::crossProduct(normal_, u_);
}

//=============================================================================
Point2F Plane3::uv(const Point3F& pt) const
{
    Vector3F p(pt.x(), pt.y(), pt.z());

    double u = Vector3F::getDotProduct(p, getU());
    double v = Vector3F::getDotProduct(p, getV());

    return Point2F(u, v);
}

//=============================================================================
Point3F Plane3::getPoint(const Point2F& uv, double d) const
{
    Vector3F du = u_; du.setLength(uv.x());
    Vector3F dv = v_; du.setLength(uv.y());
    Vector3F n = normal_; if (d != 0) n.setLength(d);

    Point3F r = origin_;
    r.add(du);
    r.add(dv);
    if (d != 0) r.add(n);

    return r;
}

//=============================================================================
