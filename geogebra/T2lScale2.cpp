//
// Copyright (C) 2015, 2017 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lScale2.h"
#include <assert.h>

using namespace T2l;

//=============================================================================
Scale2::Scale2( double scaleX, double scaleY ) :
    scaleX_(scaleX),
    scaleY_(scaleY)
{
    if (scaleX_ == 0) scaleX_ = 10e-9;
    if (scaleY_ == 0) scaleY_ = 10e-9;
}

//=============================================================================
const bool Scale2::operator==(const Scale2& other)
{
    if ( scaleX_ != other.scaleX_ ) return false;
    if ( scaleY_ != other.scaleY_ ) return false;

    return true;
}

//=============================================================================
Point2F Scale2::transform( const Point2F& pt ) const
{
    return Point2F( pt.x()*scaleX_,
                    pt.y()*scaleY_ );
}

//=============================================================================
Point2F Scale2::transformRev( const Point2F& pt ) const
{
    return Point2F( pt.x()/scaleX_,
                            pt.y()/scaleY_ );
}

//=============================================================================
void Scale2::scaleXSet(double scale)
{
    scaleX_ = scale;
    if (scaleX_ == 0) scaleX_ = 10e-9;
}

//=============================================================================
void Scale2::scaleYSet(double scale)
{
    scaleY_ = scale;
    if (scaleY_ == 0) scaleY_ = 10e-9;
}

//=============================================================================
void Scale2::scaleSet(double scale, Scale2::Dir dir)
{
    if (scale == 0) { assert(0); return; }

    switch (dir)
    {
    case Scale2::X:
        scaleXSet(scale);
        break;
    case Scale2::Y:
        scaleYSet(scale);
        break;
    case Scale2::XY:
        scaleXSet(scale);
        scaleYSet(scale);
        break;
    }
}

//=============================================================================
double Scale2::scale(Scale2::Dir dir) const
{
    switch (dir)
    {
    case Scale2::X:
        return scaleX_;
    case Scale2::Y:
        return scaleY_;
    case Scale2::XY:
        assert( scaleX_ == scaleY_);
        return scaleX_;
        break;
    }

    assert(0);
    return scaleX_;
}

//=============================================================================
bool Scale2::isIdentity() const
{
    if ( scaleX() != 1.0 ) return false;
    if ( scaleY() != 1.0 ) return false;

    return true;
}

//=============================================================================
