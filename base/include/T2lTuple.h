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

#include <string>
#include <array>

namespace T2l {

//=============================================================================
template<class T, int N = 2> class  Tuple {
///< Base clas for Point and Vector.
//=============================================================================
public:
// <CONSTRUCTION>
    Tuple() { for (int i = 0; i < N; i++) x_[i] = T(); }
    Tuple( const std::array<T, N>& values ) { for ( int i = 0; i < N; i++ ) x_[i] = values[i]; }
//=============================================================================
// <ITEMS>
    int n() { return N; }

    T    get( int index ) const { return x_[index]; }
    void set( int index, T value ) { x_[index] = value; }

    bool operator==(const Tuple<T, N>& t); //TODO include epsilon?
    bool operator!=(const Tuple<T, N>& t) { return !operator==(t); }
protected:
//<DATA>
    std::array<T, N> x_;
    //T x_[N]; //not safe, but possible to debug in Creator
};

typedef Tuple<int, 2> Tuple2I;

//=============================================================================
template<class T, int N>
bool Tuple<T, N>::operator==(const Tuple<T, N>& t)
{
    for ( int i = 0; i < N; i++ ) {
        if(t.x_[i] != x_[i]) return false;
    }

    return true;
}

//=============================================================================
} // namespace t2l
