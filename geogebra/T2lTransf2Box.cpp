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
#include "T2lTransf2Box.h"
#include "T2lScale2.h"
#include <assert.h>

using namespace T2l;

//=============================================================================
Transf2Box::Transf2Box( const Box2F& before, const Box2F& after ) :
    before_(before),
    after_(after)
{
}

//=============================================================================
Point2F Transf2Box::transform( const Point2F& pt ) const
{
    Point2F result(pt);

    Point2F ptBefore = before_.getPoint(0);
    Point2F ptAfter  = after_.getPoint(0);

    result.add(Vector2F(-ptBefore.x(), -ptBefore.y()));

    result = Scale2( after_.x().getLength()/before_.x().getLength(),
                     after_.y().getLength()/before_.y().getLength() ).transform(result);

    result.add(Vector2F(ptAfter.x(), ptAfter.y()));

    return result;
}

//=============================================================================
Point2F Transf2Box::transformRev( const Point2F& pt ) const
{
    return Transf2Box(after_, before_).transform(pt);
}

//=============================================================================
bool Transf2Box::isIdentity() const
{
    if ( before_ == after_ ) return true;
    return false;
}

//=============================================================================
