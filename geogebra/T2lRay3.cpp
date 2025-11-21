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
#include "T2lRay3.h"
#include "T2lPlane3.h"
#include "T2lDefs.h"

using namespace T2l;

//=============================================================================
Ray3::Ray3( const Point3F& origin, const Vector3F& dir ) :
    origin_(origin),
    dir_(dir)
{
}

//=============================================================================
Ray3::Ray3( const Point3F& first, const Point3F& second) :
    origin_(first),
    dir_(first, second)
{
}

//=============================================================================
Point3F Ray3::getPoint(double parameter) const
{
    Vector3F delta = dir_;
    delta.multiply(parameter);
    Point3F result =  origin_;
    result.add(delta);

    return result;
}

//=============================================================================
std::optional<Point3F> Ray3::getIntersect(const Plane3& plane) const
{
    double denom = Vector3F::getDotProduct(dir_, plane.getNormal());
    if (std::abs(denom) < T2L_EPS) return std::nullopt; // parallel ray and plane

    double t = Vector3F::getDotProduct(Vector3F(origin_, plane.getOrigin()), plane.getNormal())/denom;
    if (t < 0.0) return std::nullopt;// If t < 0 → intersection behind ray origin

    return getPoint(t);
}

//=============================================================================
