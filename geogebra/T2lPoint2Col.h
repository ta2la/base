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
#include "T2lVector2.h"
#include "T2lPoint2.h"
#include "T2lBox2.h"
#include <vector>
#include <assert.h>

namespace T2l {

//=============================================================================
template<class T> class Point2Col {
//=============================================================================
public:
// <CONSTRUCTION>
    Point2Col() { it_ = points_.end(); }
    Point2Col( const Point2Col<T>& other);
    Point2Col( const Point2<T>& p0) { add(p0); }
    Point2Col( const Point2<T>& p0, const Point2<T>& p1) { add(p0); add(p1); }
// <ITEMS>
    int count() const { return points_.size(); }
    Point2<T> get(int index) const;
    Point2<T>& getRef(int index);

    void add(const Point2<T>& point) { points_.push_back(point); }
    void add(const Point2Col& points);

    void clean() { points_.clear(); }
    void removeLast() { if (count() == 0) return; points_.pop_back(); }

    Box2<T> bound() const;
//=============================================================================
// <METHODS>
    typedef std::vector< Point2<T> >                    List;
    typedef typename std::vector< Point2<T> >::iterator Iterator;

    List      points_;
    Iterator  it_;
    static Point2<T>& null_() { static Point2<T> result; return result; }
};

typedef Point2Col<double> Point2FCol;
typedef Point2Col<int>    Point2ICol;

//=============================================================================
template<class T>
Point2Col<T>::Point2Col( const Point2Col<T>& other)
{
    for( int i = 0; i < other.count(); i++ ) {
        add( other.get(i) );
    }
}

//=============================================================================
template<class T>
Point2<T> Point2Col<T>::get(int index) const
{
    if (count() == 0) return null_();
    while (index >= count()) index -= count();
    while (index < 0) index += count();
    return points_[index];
}

//=============================================================================
template<class T>
Point2<T>& Point2Col<T>::getRef(int index)
{
    if ( ( index < 0 ) || (index >= count()) ) return null_();
    return points_[index];
}

//=============================================================================
template<class T>
void Point2Col<T>::add(const Point2Col& points)
{
    if (&points == this) {
        assert(0);
        return;
    }

    for (int i = 0; i < points.count(); i++) {
        add( points.get(i) );
    }
}

//=============================================================================
template<class T>
Box2<T> Point2Col<T>::bound() const
{
    Box2<T> result;

    for (int i = 0; i < count(); i++) {
        result.inflateTo(get(i));
    }

    return result;
}

} // namespace T2l
