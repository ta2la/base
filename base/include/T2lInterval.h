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

#include <utility>

namespace T2l {

//=============================================================================
template<class T> class  Interval {
///< Interval of values. Interval is mentioned always opened.
//=============================================================================
public:
// <CONSTRUCTION>
    Interval() : from_(0), to_(-1) {}
    Interval( const T& from, const T& to );

    bool operator==(const Interval<T>& other) const;
    bool operator!=(const Interval<T>& other) const { return !operator==(other); }
// <METHODS>
    bool isEmpty() const { return to_ < from_; }

    T beg() const { return from_; }
    T end() const { return to_; }

    T getLength() const;
    T getCenter() const { return 0.5*(from_+to_); }

// <METHODS> - changing
    void setBeg( const T& from ) { from_ = from; }
    void setEnd( const T& to )   { to_ = to; }

    Interval<T>& inflateBy(const T& value);
    Interval<T>& inflateTo(const T& value);
    Interval<T>& moveBy(const T& value) { from_ += value, to_ += value; return *this; }
    Interval<T>& setLength(const T& value);

    Interval<T>& inflateBy(const Interval<T>& value);
    Interval<T>& intersectWidth(const Interval<T>& value);

// <METHODS> - relationships
    bool isInside(const T& value) const;
    bool isInside(const Interval<T>& value) const;
    bool isColiding(const Interval<T>& value, bool closed = true) const;
    T getDistanceTo(const T& value);
//=============================================================================
protected:
// <DATA>
    T from_;
    T to_;
};

typedef Interval<int>    IntervalI;

//=============================================================================
template<class T>
Interval<T>::Interval(const T& from, const T& to) :
    from_(from),
    to_(to)
{
    if (from_ > to_) std::swap(from_, to_);
}

//=============================================================================
template<class T>
bool Interval<T>::isInside(const T& value) const
{
    if ( isEmpty() ) return false;

    if (value < from_) return false;
    return value <= to_;
}

//=============================================================================
template<class T>
bool Interval<T>::isInside(const Interval<T>& value) const
{
    if ( isEmpty() ) return false;

    if ( isInside(from_) == false) return false;
    if ( isInside(to_) == false) return false;

    return true;
}

//=============================================================================
template<class T>
bool Interval<T>::operator==(const Interval<T>& other) const
{
    if ( ( isEmpty() ) && other.isEmpty() ) return true;
    if ( beg() != other.beg() ) return false;
    if ( end() != other.end() ) return false;

    return true;
}

//=============================================================================
template<class T>
bool Interval<T>::isColiding(const Interval<T>& value, bool closed) const
{
    if ( isEmpty() ) return false;
    if ( value.isEmpty() ) return false;

    if (closed) {
        if (beg() >= value.end()) return false;
        if (value.beg() > end()) return false;
    }
    else {
        if (beg() >= value.end()) return false;
        if (value.beg() > end()) return false;
    }

    return true;
}

//=============================================================================
template<class T>
T Interval<T>::getLength() const
{
    if ( isEmpty() ) return 0;

    if ( std::is_integral<T>::value ) { //TODO optimize without if
        return (to_-from_+1);
    }
    else {
        return to_-from_;
    }
}

//=============================================================================
template<class T>
T Interval<T>::getDistanceTo(const T& value)
{
    if (value < from_) return from_-value;
    if (value > to_) return value-to_;
    return 0;
}

//=============================================================================
template<class T>
Interval<T>& Interval<T>::inflateBy(const T& value)
{
    if (isEmpty()) return *this;

    from_ -= value;
    to_   +=value;

    return *this;
}

//=============================================================================
template<class T>
Interval<T>& Interval<T>::inflateTo(const T& value)
{
    if (isEmpty()) {
        from_ = to_ = value;
        return *this;
    }
    if (value < from_) from_ = value;
    else if (value > to_) to_ = value;
    return *this;
}

//=============================================================================
template<class T>
Interval<T>& Interval<T>::inflateBy(const Interval<T>& value)
{
    if (isEmpty()) { *this = value; return *this; }
    if ( value.from_ < from_) from_ = value.from_;
    if ( value.to_   > to_)   to_ = value.to_;
    return *this;
}

//=============================================================================
template<class T>
Interval<T>& Interval<T>::intersectWidth(const Interval<T>& value)
{
    if ( value.from_ > from_) from_ = value.from_;
    if ( value.to_ < to_)   to_ = value.to_;
    return *this;
}

//=============================================================================
template<class T>
Interval<T>& Interval<T>::setLength(const T& value)
{
    double center = getCenter();
    double length2 = getLength()/2.0;
    from_ = center-length2;
    to_   = center-length2;
}

//=============================================================================
} // namespace t2l
