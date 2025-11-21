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
#include "T2lLine2.h"

using namespace T2l;

//=============================================================================
Line2::Line2(const Point2F& from, const Point2F& to) :
    Ray2( from, Vector2F(from, to) )
{
}

//=============================================================================
bool Line2::intersectParam( const Line2& line1, const Line2& line2, double& parameter )
{
    bool exists = Ray2::intersectParam(line1, line2, parameter, false);
    if ( parameter+10e-12 < 0 ) exists = false;
    if ( parameter-10e-12 > 1.0 ) exists = false;
    if ( exists == false ) return exists;

    double parameterEnd;
    Ray2::intersectParam(line2, line1, parameterEnd, false);
    if ( parameterEnd+10e-12 < 0 ) exists = false;
    if ( parameterEnd-10e-12 > 1.0 ) exists = false;

    return exists;
}

//=============================================================================
