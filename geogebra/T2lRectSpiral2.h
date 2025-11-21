//
// Copyright (C) 2019 Petr Talla. [petr.talla@gmail.com]
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

namespace T2l {
//            +--------+  2
//            |  +-----+  1
//            |  |  +  |  0
//            |  +--+  | -1
//            +--------+ -2
//           -2 -1  0  1

//=============================================================================
class RectSpiral2 {
//=============================================================================
public:
// <CONSTRUCTION>
    RectSpiral2();
    ~RectSpiral2() {}
// <METHODS>
    void    next();
    int     index() { return index_; }
    Point2I current() { return current_; }
//=============================================================================
//<DATA>
    int      index_;
    Vector2I progress_;
    Point2I  current_;
//<INTERNALS>

};

} // namespace t2l
