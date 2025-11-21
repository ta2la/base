//
// Copyright (C) 2017 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lTransf2.h"

namespace T2l {

//=============================================================================
class Scale2 : public Transf2 {
//=============================================================================
public:
//<ENUMS>
    enum Dir{ X, Y, XY };
//<CONSTRUCTION>
    Scale2 ( double scaleX, double scaleY );

    const bool operator==(const Scale2& other);
    const bool operator!=(const Scale2& other) { return operator==(other); }
//<METHODS>
    double scaleX() const { return scaleX_; }
    double scaleY() const { return scaleY_; }

    void scaleXSet(double scale);
    void scaleYSet(double scale);

    void scaleSet(double scale, Scale2::Dir dir);
    double scale(Scale2::Dir dir) const;
//=============================================================================
//<OVERRIDES>
    virtual T2l::Point2F transform( const Point2F& pt )    const;
    virtual T2l::Point2F transformRev( const Point2F& pt ) const;
    virtual bool         isIdentity()                      const;
protected:
// <DATA>
    double scaleX_;
    double scaleY_;
// <HIDDING>

};

} // namespace t2l
