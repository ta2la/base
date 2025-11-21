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

// std
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI        3.14159265358979323846264338327950288
#endif

namespace T2l {

//=============================================================================
class Angle {
///< Angular value. Has not origin.
//=============================================================================
public:
// <ENUMS>
    enum EAngleUnits { UNITS_DEG, UNITS_RAD };
// <CONSTRUCTION>
    Angle(double angle, EAngleUnits units = UNITS_DEG);
    static Angle angleFull()    { return Angle(360.0); }
    static Angle angleStright() { return Angle(180.0); }
    static Angle angleRight()   { return Angle(90.0);  }
// <METHODS>
    double get(EAngleUnits units = UNITS_DEG) const;
    Angle& multiply(double multiplier) { radNorm_(angleRad_*multiplier); return *this; }
    Angle& rotate(const Angle& byAngle);
//=============================================================================
protected:
// <DATA>
    double angleRad_;
// <INTERNALS>
    static double degToRad_(double deg) { return deg * 2.0*M_PI/360.0; }
    static double radToDeg_(double rad) { return rad * 360.0/(2.0*M_PI); }
    static double radNorm_(double rad);
    void norm_(){ angleRad_ =  radNorm_(angleRad_); }
};

} // namespace t2l
