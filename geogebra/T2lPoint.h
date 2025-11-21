//
// Copyright (C) 2015, 2016 Petr Talla. [petr.talla@gmail.com]
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

#include <math.h>

namespace T2l {

//=============================================================================
template<class T, int N = 2> class  Point : public Tuple<T, N> {
///< N dimensional point.
//=============================================================================
public:
// <CONSTRUCTION>
    Point() {}
    Point( const std::array<T, N>& values ) : Tuple<T, N>(values) {}
    Point( const Tuple<T, N>& other ) : Tuple<T, N>::Tuple(other) {}
//=============================================================================
// <METHODS>
    Point<T, N>& add(const Vector<T, N>&);
    static double distance(const Point<T, N>& p0, const Point<T, N>& p1);
    static Point<T,N> center(const Point<T, N>& p0, const Point<T, N>& p1);
};

//=============================================================================
template<class T, int N>
Point<T, N>& Point<T,N>::add(const Vector<T, N>& vec)
{
    for ( int i = 0; i < N; i++ ) {
        Tuple<T, N>::x_[i] += vec.get(i);
    }
    return *this;
}

//=============================================================================
template<class T, int N>
double Point<T,N>::distance(const Point<T, N>& p0, const Point<T, N>& p1)
{
    double result = 0;
    for (int i = 0; i < N; i++) {
        double v0 = p0.get(i);
        double v1 = p1.get(i);

        double value = fabs(v0-v1);

        result += value*value;
    }

    return sqrt(result);
}

//=============================================================================
template<class T, int N>
Point<T,N> Point<T,N>::center(const Point<T, N>& p0, const Point<T, N>& p1)
{
    Point<T,N> result;
    for (int i = 0; i < N; i++) {
        result.set(i, (p0.get(i)+p1.get(i))/2.0);
    }

    return result;
}

} // namespace T2l
