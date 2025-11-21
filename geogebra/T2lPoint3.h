//
// Copyright (C) 2023 Petr Talla. [petr.talla@gmail.com]
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


#include "T2lPoint.h"

namespace T2l {

//=============================================================================
template<class T> class Point3 : public Point<T, 3> {
///< 3 dimensional point specialization.
//=============================================================================
public:
// <CONSTRUCTION>
    Point3() {}
    Point3( T x, T y, T z ) : Point<T, 3>( { x, y, z } ) {}
    Point3( const Point<T, 3>& other) : Point<T, 3>( { other.get(0), other.get(1), other.get(2)} ) {}
//=============================================================================
// <ITEMS>
    T x() const { return Tuple<T, 3>::x_[0]; }
    T y() const { return Tuple<T, 3>::x_[1]; }
    T z() const { return Tuple<T, 3>::x_[2]; }
// <METHODS>
    operator Point<T, 3>() const {
        return Point<T, 3>({this->x(), this->y(), this->z()});
    }
};

//template<class T>
/*void Point3<T>::swap()
{
    std::swap(Tuple<T, 3>::x_[0], Tuple<T, 2>::x_[1], Tuple<T, 3>::x_[2]);
}*/

typedef Point3<int>    Point3I;
typedef Point3<double> Point3F;

} // namespace t2l

