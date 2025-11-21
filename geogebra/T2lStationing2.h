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

#include "T2lPolyLine2.h"

namespace T2l {

//=============================================================================
class Stationing2 {
//=============================================================================
public:
// <CONSTRUCTION>
    Stationing2();
    ~Stationing2() {}
// <METHODS>
    static void   cutPart(T2l::PolyLine2& source, T2l::PolyLine2& result, double parameterBeg, double parameterEnd);
    static double parameterOffset(T2l::PolyLine2& source, double parameter, double offset);
//=============================================================================
protected:
//<DATA>
//<INTERNALS>
};

} // namespace t2l
