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

#include "T2lVector.h"
#include "T2lAngleXcc.h"
#include <string>
#include <array>

namespace T2l {

//=============================================================================
template<class T> class Vector2 : public Vector<T, 2> {
///< 2d vector specialization.
//=============================================================================
public:
// <CONSTRUCTION>
    Vector2() {}
    Vector2( T x, T y ) : Vector<T,2>( {x, y} ) {}
    Vector2( const Tuple<T, 2>& beg, const Tuple<T, 2>& end );
    Vector2( const AngleXcc& angle,  double radius);
//=============================================================================
// <ITEMS>
    T x() const { return Vector<T,2>::x_[0]; }
    T y() const { return Vector<T,2>::x_[1]; }

// <METHODS>
    Vector2<T>& setPerpendLeft();
    AngleXcc getAngle() const;
    void rotateCc(const Angle& angle);
    bool isOnLeftOf( const Vector2<T>& second) { return crossProduct(*this, second) > 0; }
    static Angle angleBetween( const Vector<T>& v0, const Vector<T>& v1 );
    static double crossProduct( const Vector2<T>& v0, const Vector2<T>& v1 );
    void flipX() { Vector<T,2>::x_[1] = -Vector<T,2>::x_[1]; }
    void flipY() { Vector<T,2>::x_[0] = -Vector<T,2>::x_[0]; }
};

//=============================================================================
typedef Vector2<int>    Vector2I;
typedef Vector2<double> Vector2F;

//=============================================================================
template<class T>
Vector2<T>::Vector2(const Tuple<T, 2>& beg, const Tuple<T, 2>& end) :
    Vector<T,2>( { end.get(0)-beg.get(0), end.get(1)-beg.get(1) } )
{
}

//=============================================================================
template<class T>
Vector2<T>::Vector2(const AngleXcc& angle, double radius)
{
    double angleRad = angle.get(Angle::UNITS_RAD);
    Vector<T, 2>::x_[0] = radius*cos(angleRad);
    Vector<T, 2>::x_[1] = radius*sin(angleRad);
}

//=============================================================================
template<class T>
void Vector2<T>::rotateCc(const Angle& angle)
{
    AngleXcc angleAct = getAngle();
    double radius = Vector<T, 2>::getLength();

    angleAct.rotate(angle);

    *this = Vector2<T>(angleAct, radius);
}

//=============================================================================
template<class T>
Vector2<T>& Vector2<T>::setPerpendLeft()
{
    T temp = x();
    Vector<T, 2>::x_[0] = -y();
    Vector<T, 2>::x_[1] = temp;

    return *this;
}

//=============================================================================
template<class T>
AngleXcc Vector2<T>::getAngle() const
{
    if ( Vector<T, 2>::isZero() ) return AngleXcc(0);

    double X = x();
    double Y = y();

    double result = asin(fabs(Y/Vector<T, 2>::getLength()));

    if ( ( X<=0) && (Y>=0) ) result = M_PI   - result;
    else if ( ( X<=0) && (Y<=0) ) result = M_PI   + result;
    else if ( ( X>=0) && (Y<=0) ) result = 2*M_PI - result;

    return AngleXcc( result, Angle::UNITS_RAD );
}

//=============================================================================
template<class T>
Angle Vector2<T>::angleBetween( const Vector<T>& v0, const Vector<T>& v1)
{
    double cos = Vector<T, 2>::getDotProduct(v0, v1) / (v0.getLength()*v1.getLength());
    if (cos >  1.0) cos =  1.0;
    if (cos < -1.0) cos = -1.0;

    double result = acos(cos);
    if (result >= M_PI-10e-12) result = M_PI;

    return Angle(result, Angle::UNITS_RAD);
}

//=============================================================================
template<class T>
double Vector2<T>::crossProduct( const Vector2<T>& v0, const Vector2<T>& v1 )
{
    return v0.x()*v1.y() - v0.y()*v1.x();
}

//=============================================================================

} // namespace t2l



