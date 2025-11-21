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


#include "T2lSize.h"

namespace T2l {

//=============================================================================
template<class T> class Size2 : public Size<T, 2> {
//=============================================================================
public:
// <CONSTRUCTION>
    Size2() {}
    Size2( T w, T h ) : Size<T, 2>( { w, h } ) {}
//=============================================================================
// <ITEMS>
    T w() const { return Tuple<T, 2>::x_[0]; }
    T h() const { return Tuple<T, 2>::x_[1]; }

    double area() { return w()*h(); }
};

typedef Size2<int>    Size2I;
typedef Size2<double> Size2F;

} // namespace t2l
