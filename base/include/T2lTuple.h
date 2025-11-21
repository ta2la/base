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

#include <cstring>
#include <array>
#include <vector>

namespace T2l {

//=============================================================================
template<class T, int N = 2> class  Tuple {
///< Base clas for Point and Vector.
//=============================================================================
public:
// <CONSTRUCTION>
    Tuple() {
        std::memcpy(x_, zeroes_, N * sizeof(T));
    }
    Tuple( const std::array<T, N>& values ) {
        std::memcpy(x_, values.data(), N * sizeof(T));
    }
    Tuple(const Tuple<T, N>& other) {
        std::memcpy(x_, other.x_, N * sizeof(T));
    }
    template<int M>
    Tuple(const Tuple<T, M>& other) {
        constexpr int minSize = (M < N) ? M : N;
        std::memcpy(x_, other.x_, minSize * sizeof(T));
        if (N > M) { //TODO constexpr C++17
            std::fill(x_+M, x_+N,T{});
        }
    }
    Tuple& operator=(const Tuple& other) {
        if (this!=&other) {
            std::memcpy(x_, other.x_, N * sizeof(T));
        }
        return *this;
    }
//=============================================================================
// <ITEMS>
    int n() { return N; }

    T    get( int index ) const { return x_[index]; }
    void set( int index, T value ) { x_[index] = value; }

    bool operator==(const Tuple<T, N>& t); //TODO include epsilon?
    bool operator!=(const Tuple<T, N>& t) { return !operator==(t); }

    std::vector<T> toStdVector() const { return std::vector<T>(x_, x_+N); }
//protected:
//<DATA>
    T x_[N]; //--TODO rewrite in std::array
    static T zeroes_[N];
};

template<class T, int N>
T Tuple<T, N>::zeroes_[N] = {};

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
