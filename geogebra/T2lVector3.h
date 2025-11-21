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

#include "T2lTuple.h"
#include "T2lVector.h"
#include "T2lAngleXcc.h"
#include "T2lVector2.h"

namespace T2l {

template<class T> class Vector3;
typedef Vector3<int>    Vector3I;
typedef Vector3<double> Vector3F;

//=============================================================================
template<class T> class Vector3 : public Vector<T, 3> {
///< 3 dimensional vector specialization.
//=============================================================================
public:
// <CONSTRUCTION>
    Vector3() {}
    Vector3( T x, T y, T z ) : Vector<T, 3>( { x, y, z } ) {}
    Vector3( const Vector<T, 3>& other) : Vector<T, 3>( { other.get(0), other.get(1), other.get(2)} ) {}
    Vector3( const Tuple<T, 3>& beg, const Tuple<T, 3>& end );
//=============================================================================
// <ITEMS>
    T x() const { return Tuple<T, 3>::x_[0]; }
    T y() const { return Tuple<T, 3>::x_[1]; }
    T z() const { return Tuple<T, 3>::x_[2]; }
// <METHODS>
    static Vector3<T> crossProduct(const Vector3<T>& v0, const Vector3<T>& v1);
    void swap(); //???

    std::pair<Tuple<double, 2>, double> toGroundElev();
    static Vector3F fromGroundElev(const Tuple<double, 2>& xy, const AngleXcc& angle);
};

//=============================================================================
template<class T>
Vector3<T>::Vector3(const Tuple<T, 3>& beg, const Tuple<T, 3>& end) :
    Vector<T,3>( { end.get(0)-beg.get(0), end.get(1)-beg.get(1), end.get(2)-beg.get(2) } )
{
}

//=============================================================================
template<class T>
Vector3<T> Vector3<T>::crossProduct( const Vector3<T>& v0, const Vector3<T>& v1 )
{
    return Vector3<T>(
        v0.y() * v1.z() - v0.z() * v1.y(),  // X component
        v0.z() * v1.x() - v0.x() * v1.z(),  // Y component
        v0.x() * v1.y() - v0.y() * v1.x()   // Z component
        );
}

template<class T>
std::pair<Tuple<double, 2>, double> Vector3<T>::toGroundElev()
{
    Vector2F ground(x(), y());
    Vector2F elevVect(ground.getLength(), z());

    //Tuple<double, 2> result({ground.x(), ground.y()});

    return {  Tuple<double, 2>({ground.x(), ground.y()}),
              elevVect.getAngle().get() };
}

template<class T>
Vector3F Vector3<T>::fromGroundElev(const Tuple<double, 2>& xy, const AngleXcc& angle)
{
    double x = xy.get(0);
    double y = xy.get(1);
    double z = Vector2F(x, y).getLength() * std::tan(angle.get(Angle::UNITS_RAD));

    return Vector3F(x, y, z);
}

} // namespace T2l

