//
// Copyright (C) 2013 Kinalisoft s.r.o., kinalisoft.eu
// Copyright (C) 2014, 2015 Petr Talla. [petr.talla@gmail.com]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=============================================================================
#pragma once

// base
#include "T2lTuple.h"

#include <string>

namespace T2l {

//=============================================================================
class  Color {
//=============================================================================
public:
    enum EPredef { WHITE, BLACK, RED, GREEN, BLUE, YELLOW, CYAN,
                   MAGENTA, GRAY_LIGHT, GRAY, GRAY_DARK, ORANGE, BROWN };
    //http://www.w3schools.com/tags/ref_color_tryit.asp
// <CONSTRUCTION>
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(EPredef color = BLACK);

    static Color read(const char* color);
    std::string write() const;
// <METHODS>
    inline bool operator == (const Color &c) const;
    inline bool operator != (const Color &c) const;

    unsigned char r() const {return r_; }
    unsigned char g() const {return g_; }
    unsigned char b() const {return b_; }

    Color supplement() const;
    Color& add(int value);

    float rf() const { return (static_cast<float>(r_))/255.0; }
    float gf() const { return (static_cast<float>(g_))/255.0; }
    float bf() const { return (static_cast<float>(b_))/255.0; }

    static double distanceSq(const Color& c1, const Color& c2);

    //T2l::Tuple<unsigned char, 3> get_tuple() { return T2l::Tuple<unsigned char, 3>( { { r_, g_, b_ } } ); }
//=============================================================================
private:
// <DATA>
    unsigned char r_;
    unsigned char g_;
    unsigned char b_;
};

//=============================================================================
inline bool Color::operator == (const Color &c) const
{
    if (r_ != c.r_) return false;
    if (g_ != c.g_) return false;
    if (b_ != c.b_) return false;

    return true;
}

//=============================================================================
inline bool Color::operator != (const Color &c) const
{
    if (r_ != c.r_) return true;
    if (g_ != c.g_) return true;
    if (b_ != c.b_) return true;

    return false;
}

} //namespace T2l

//=============================================================================
