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
#include "T2lInterval.h"

namespace T2l {

//=============================================================================
template<class T, int N = 2> class Box : public Point<Interval<T>, N> {
///< N dimensional Box parallel to coordinate system.
//=============================================================================
public:
// <CONSTRUCTION>
    Box() {}
    Box( const std::array<Interval<T>, N>& intervals ) : Point<Interval<T>, 2>( intervals ) {}
//=============================================================================
    Point<T, N> getCenter() const;

    bool isEmpty() const;

    double quantum() const;

    Box<T, N>& inflateBy(double value);
    Box<T, N>& inflateBy(const Box<T, N>& other);
    Box<T, N>& inflateTo(const Point<T, N>& pt);

    Box<T, N>& intersectWidth( const Box<T, N>& other );

    bool isInside( const Point<T, N>& point) const;
    bool isInside( const Box<T, N>& box) const;
};

//=============================================================================
template<class T, int N>
double Box<T, N>::quantum() const
{
    double result = Point< Interval<T>, N>::get(0).getLength();

    for (int i(1); i < N; i++) {
        result *= Point<Interval<T>, N>::get(i).getLength();
    }

    return result;
}

//=============================================================================
template<class T, int N>
Box<T, N>& Box<T, N>::inflateBy(double value)
{
    for (int i(0); i < N; i++) {
        Point< Interval<T>, N>::x_[i].inflateBy(value);
    }

    return *this;
}

//=============================================================================
template<class T, int N>
Box<T, N>& Box<T, N>::inflateTo(const Point<T, N>& pt)
{
    for (int i = 0; i < N; i++) {
        Point< Interval<T>, N>::x_[i].inflateTo(pt.get(i));
    }

    return *this;
}

//=============================================================================
template<class T, int N>
Box<T, N>& Box<T, N>::intersectWidth( const Box<T, N>& other )
{
    for (int i = 0; i < N; i++) {
        Point< Interval<T>, N>::x_[i].intersectWidth(other.get(i));
    }

    return *this;
}

//=============================================================================
template<class T, int N>
Box<T, N>& Box<T, N>::inflateBy(const Box<T, N>& other)
{
    for (int i = 0; i < N; i++) {
        Point< Interval<T>, N>::x_[i].inflateBy(other.get(i));
    }

    return *this;
}

//=============================================================================
template<class T, int N>
bool Box<T, N>::isEmpty() const
{
    for (int i = 0; i < N; i++) {
        if ( Point< Interval<T>, N>::x_[i].isEmpty() ) return true;
    }

    return false;
}

//=============================================================================
template<class T, int N>
bool Box<T, N>::isInside( const Point<T, N>& point) const
{
    for (int i = 0; i < N; i++) {
        if ( Point< Interval<T>, N>::x_[i].isInside(point.get(i)) == false ) return false;
    }

    return true;
}

//=============================================================================
template<class T, int N>
bool Box<T, N>::isInside( const Box<T, N>& box) const
{
    for (int i = 0; i < N; i++) {
        if ( Point< Interval<T>, N>::x_[i].isInside(box.get(i)) ) return true;
    }

    return false;
}

//=============================================================================
template<class T, int N>
Point<T, N> Box<T, N>::getCenter() const
{
    Point<T, N> result;

    for (int i = 0; i < N; i++) {
        T coord = Point< Interval<T>, N>::x_[i].getCenter();
        result.set(i, coord);
    }

    return result;
}


//=============================================================================
} // namespace t2l
