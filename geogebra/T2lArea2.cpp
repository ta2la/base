//
// Copyright (C) 2025 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lArea2.h"

using namespace T2l;

//=============================================================================
Area2::Area2() :
    points_(true)
{
}

//=============================================================================
bool Area2::isInside( const Point2F& pt )
{
    bool result = false;

    int count = points_.points().count();

    for (int i = 0; i < count; i++) {
        Point2F p0 = points_.points().get(i);
        Point2F p1 = points_.points().get(i+1);

        bool a = ((p0.y()<=pt.y()) && (pt.y()<p1.y()));
        bool b = ((p1.y()<=pt.y()) && (pt.y()<p0.y()));
        bool c = (pt.x() < (p1.x()-p0.x()) * (pt.y()-p0.y()) / (p1.y()-p0.y())+p0.x());

        if ( (a||b) && c ) result = !result;
    }

    return result;
}

//=============================================================================
double Area2::areaCalc()
{
    double area = 0.0;
    for(int i = 0; i < points().count(); i++) {
        Point2F p0 = points().get(i-1);
        Point2F p1 = points().get(i);
        area += (p0.x()*p1.y())-(p0.y()*p1.x());
    }
    return fabs(area)*0.5;
}

//=============================================================================
