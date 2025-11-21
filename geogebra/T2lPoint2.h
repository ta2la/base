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


#include "T2lPoint.h"

namespace T2l {

//=============================================================================
template<class T> class Point2 : public Point<T, 2> {
///< 2 dimensional point specialization.
//=============================================================================
public:
// <CONSTRUCTION>
    Point2() {}
    Point2( T x, T y ) : Point<T, 2>( { x, y } ) {}
    Point2( const Point<T, 2>& other) : Point<T, 2>( { other.get(0), other.get(1) } ) {}
//=============================================================================
// <ITEMS>
    T x() const { return Tuple<T, 2>::x_[0]; }
    T y() const { return Tuple<T, 2>::x_[1]; }
// <METHODS>
    void swap();
};

template<class T>
void Point2<T>::swap()
{
    std::swap(Tuple<T, 2>::x_[0], Tuple<T, 2>::x_[1]);
}

typedef Point2<int>    Point2I;
typedef Point2<double> Point2F;

} // namespace t2l

