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
#include "T2lAngle.h"

using namespace T2l;

//=============================================================================
Angle::Angle(double angle, EAngleUnits units)
{
    if (units == UNITS_DEG) {
        angleRad_ = degToRad_(angle);
    }
    else {
        angleRad_ = angle;
    }

    angleRad_ = radNorm_(angleRad_);
}

//=============================================================================
double Angle::get(EAngleUnits units) const
{
    if (units == UNITS_DEG) {
        return radToDeg_(angleRad_);
    }

    return angleRad_;
}

//=============================================================================
double Angle::radNorm_(double rad) //TODO
{
    double result = rad;
    while ( result >= 2*M_PI ) result -= 2*M_PI;
    while ( result < 0.0     ) result += 2*M_PI;
    return result;
}

//=============================================================================
Angle& Angle::rotate(const Angle& byAngle)
{
    angleRad_ += byAngle.angleRad_;
    norm_();
    return *this;
}

//=============================================================================
