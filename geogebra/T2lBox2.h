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


#include "T2lPoint2.h"
#include "T2lVector2.h"
#include "T2lInterval.h"
#include "T2lBox.h"
#include "T2lDefs.h"

namespace T2l {

//=============================================================================
template<class T> class Box2 : public Box< T, 2> {
///< 2d box specialization.
//=============================================================================
public:
// <ENUMS>
    enum CornerIndex {
        BOT_LEFT  = 0,
        BOT_RIGHT = 1,
        TOP_RIGHT = 2,
        TOP_LEFT  = 3
    };

// <CONSTRUCTION>
    Box2() : Box<T, 2>( {Interval<T>(), Interval<T>()} ) {}
    Box2( const Interval<T>& x, const Interval<T>& y ) : Box<T, 2>( { x, y } ) {}
    Box2( const Point2F& from, const Point2F& to );

    bool operator==(const Box2<T>& other) const;
//=============================================================================
// <ITEMS>
    Interval<T> x() const { return Point< Interval<T>, 2>::x_[0]; }
    Interval<T> y() const { return Point< Interval<T>, 2>::x_[1]; }

    Point2<T> getPoint(int index) const;
    //
    //  A    3       2
    //  |
    //  |    0       1
    //  +------------------> X
    //
    //       3       2

    void inflateSideBy( T value, int side /*T2l::Side*/);

    void moveBy(const Vector2F& value);

    void setRatioAtLeast(double secondToOne);

//=============================================================================
};

template <class T>
Box2<T>::Box2( const Point2F& from, const Point2F& to ) :
    Box<T, 2>( { Interval<T>(from.x(), to.x()),
                 Interval<T>(from.y(), to.y()) } )
{
}

template <class T>
void Box2<T>::moveBy(const Vector2F& value)
{
    Point< Interval<T>, 2>::x_[0].moveBy(value.x());
    Point< Interval<T>, 2>::x_[1].moveBy(value.y());
}

template <class T>
void Box2<T>::inflateSideBy( T value, int side )
{
    if ( T2l::LEFT & side ) {
        Point< Interval<T>, 2>::x_[0].setBeg( x().beg()-value );
    }
    if ( T2l::RIGHT & side ) {
        Point< Interval<T>, 2>::x_[0].setEnd( x().end()+value );
    }
    if ( T2l::BOTTOM & side ) {
        Point< Interval<T>, 2>::x_[1].setBeg( y().beg()-value );
    }
    if ( T2l::TOP & side ) {
        Point< Interval<T>, 2>::x_[1].setEnd( y().end()+value );
    }
}

template <class T>
Point2<T> Box2<T>::getPoint(int index) const
{
    while (index < 0) index +=4;
    index %= 4;

    switch (index)
    {
    case 0: return Point2<T>( x().beg(), y().beg() );
    case 1: return Point2<T>( x().end(), y().beg() );
    case 2: return Point2<T>( x().end(), y().end() );
    case 3: return Point2<T>( x().beg(), y().end() );
    }
}

template <class T>
bool Box2<T>::operator==(const Box2<T>& other) const
{
    if ( x() != other.x() ) return false;
    if ( y() != other.y() ) return false;

    return true;
}

template <class T>
void Box2<T>::setRatioAtLeast(double secondToOne)
{
    if (x().getLength() < y().getLength()) {
        Point< Interval<T>, 2>::x_[0].setLength(y().getLength());
    }
    else {
        Point< Interval<T>, 2>::x_[1].setLength(y().getLength());
    }
}

//=============================================================================
typedef Box2<int>    Box2I;
typedef Box2<double> Box2F;

//=============================================================================

} // namespace t2l
