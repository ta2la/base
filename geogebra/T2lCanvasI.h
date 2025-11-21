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
#include "T2lBox2.h"

namespace T2l {

class Element;

//=============================================================================
class CanvasI {
//=============================================================================
public:
// <CONSTRUCTION>
    CanvasI() {}
    ~CanvasI() {}
// <METHODS>
    virtual bool  draw(Element* c) = 0;
    virtual double  width(Element* c) = 0;

    //virtual const Box2F& bound()  const   = 0; //APTA💊
    virtual double       scale() const   = 0;
    virtual double       scaleS() const   = 0;
    //virtual double       ppm()    const   = 0;

    virtual Point2F mapRealToPaper  (const Point2F& pt) const = 0;
    virtual Box2F   mapRealToPaper  (const Box2F& pt)   const = 0;
    virtual Point2F mapPaperToReal  (const Point2F& pt) const = 0;
    virtual double  mapSymbolicToReal(const double d)    const = 0;
    virtual Point2F mapSymbolicToReal(const Point2F& pt) const = 0;
//=============================================================================
};

} // namespace t2l
