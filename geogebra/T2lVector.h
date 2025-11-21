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

#include "T2lTuple.h"
#include "T2lDefs.h"
#include <string>
#include <array>
#include <math.h>

namespace T2l {

//=============================================================================
template<class T, int N = 2> class  Vector : public Tuple<T, N> {
///< N dimensional vector.
//=============================================================================
public:
// <CONSTRUCTION>
    Vector();
    Vector( const std::array<T, N>& values ) : Tuple<T, N>(values) {}
    Vector( const Tuple<T, N>& beg, const Tuple<T, N>& end );
//=============================================================================
// <METHODS>
    double getLength() const { return sqrt(getLengthSq()); }
    double getLengthSq() const;
    bool isZero() const;
    static double getDotProduct(const Vector<T, N>& u, const Vector<T, N>& v);
    Vector<T, N> projectInOther( const Vector<T, N>& other );

    Vector<T, N>& setLength(double value);
    Vector<T, N>& multiply(double value);
    Vector<T, N>& add(const Vector<T, N>& other);
    Vector<T, N>& subtract(const Vector<T, N>& other);
};

//=============================================================================
template<class T, int N>
Vector<T,N>::Vector()
{
    for ( int i{0}; i < N; i++ ) { Tuple<T, N>::x_[i] = 0; }
}

//=============================================================================
template<class T, int N>
Vector<T, N> Vector<T,N>::projectInOther( const Vector<T, N>& other )
// TODO opposite vector project in positive direction ??? !!!
{
    double k = getDotProduct(*this, other)/other.getLengthSq();

    Vector<T, N> result(other);
    result.multiply(k);
    return result;
}

//=============================================================================
template<class T, int N>
Vector<T,N>::Vector(const Tuple<T, N>& beg, const Tuple<T, N>& end)
{
    for ( int i{0}; i < N; i++ ) {
        Tuple<T, N>::x_[i] = end.get(i) - beg.get(i);
    }
}

//=============================================================================
template<class T, int N>
Vector<T, N>& Vector<T, N>::setLength(double newLength)
{
    multiply(newLength/getLength());
    return *this;
}

//=============================================================================
template<class T, int N>
double Vector<T, N>::getLengthSq() const
{
    double result = 0.0;
    for (int i = 0; i < N; i++) {
        double xi = Tuple<T, N>::x_[i];
        result += xi*xi;
    }
    return result;
}

//=============================================================================
template<class T, int N>
Vector<T, N>& Vector<T, N>::add(const Vector<T, N>& other)
{
    for (int i = 0; i < N; i++) Tuple<T, N>::x_[i] += other.x_[i];
    return *this;
}

//=============================================================================
template<class T, int N>
Vector<T, N>& Vector<T, N>::subtract(const Vector<T, N>& other)
{
    Vector<T, N> opposite(other);
    opposite.multiply(-1.0);

    return add(opposite);
}

//=============================================================================
template<class T, int N>
Vector<T, N>& Vector<T, N>::multiply(double value)
{
    for (int i =0; i < N; i++) Tuple<T, N>::x_[i] *= value;
    return *this;
}

//=============================================================================
template<class T, int N>
double Vector<T, N>::getDotProduct(const Vector<T, N>& u, const Vector<T, N>& v)
{
    double result = 0.0;
    for (int i = 0; i < N; i++) result += u.get(i)*v.get(i);
    return result;
}

//=============================================================================
template<class T, int N>
bool Vector<T, N>::isZero() const
{
    for (int i = 0; i < N; i++) {
        T xi = Tuple<T, N>::x_[i];

        if ( xi < -T2L_EPS ) return false;
        if ( xi >  T2L_EPS ) return false;
    }

    return true;
}

} // namespace t2l

//=============================================================================
