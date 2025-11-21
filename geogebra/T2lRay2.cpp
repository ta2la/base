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
#include "T2lRay2.h"

using namespace T2l;

//=============================================================================
Ray2::Ray2( const Point2F& origin, const Vector2F& dir ) :
    origin_(origin),
    dir_(dir)
{
}

//=============================================================================
Ray2::Ray2( const Point2F& first,  const Point2F& second) :
    origin_(first),
    dir_(first, second)
{
}

//=============================================================================
Point2F Ray2::getPoint(double parameter, double offset) const
{
    Vector2F delta = dir_;
    delta.multiply(parameter);
    Point2F result =  origin_;
    result.add(delta);

    if (offset == 0.0) return result;

    Vector2F offsetVec = dir_;
    offsetVec.setPerpendLeft();
    offsetVec.multiply( offset/offsetVec.getLength() );
    result.add(offsetVec);

    return result;
}

//=============================================================================
Point2F Ray2::getPointDistance(double distance, double offset)
{
    Point2F pt1       = getPoint(1.0);
    double  distance1 = Point2F::distance(origin_, pt1);

    double param = distance/distance1;

    return getPoint(param, offset);
}

//=============================================================================
bool Ray2::intersectParam( const Ray2& ray1, const Ray2& ray2, double& parameter, bool onlyExistence)
{
    double determinant = ray1.getDir().x()*ray2.getDir().y() - ray1.getDir().y()*ray2.getDir().x();
    bool exists = true;
    if ( ( determinant > -10e-12 ) && ( determinant <  10e-12 ) ) exists = false;
    if (exists == false) return false;

    if (onlyExistence) return exists;

    Vector2F delta( ray2.origin_, ray1.origin_);
    parameter = ( delta.y()*ray2.getDir().x() - delta.x()*ray2.getDir().y() ) / determinant;
    return true;
}

//=============================================================================
double Ray2::nearestParam( const Point2F& pt )
{
    double parameter = 0.0;
    Vector2F dir = getDir();
    dir.setPerpendLeft();
    intersectParam( *this, Ray2(pt, dir), parameter);
    return parameter;
}

//=============================================================================
