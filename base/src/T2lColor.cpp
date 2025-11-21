//
// Copyright (C) 2013 Kinalisoft. [kinalisoft.eu]
// Copyright (C) 2014, 2015 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lColor.h"

#include <sstream>
#include <iostream>
#include <vector>

using namespace T2l;
using namespace std;

//=============================================================================
Color::Color(unsigned char r, unsigned char g, unsigned char b) :
    r_(r),
    g_(g),
    b_(b)
{
}

//=============================================================================
Color::Color(Color::EPredef color) :
    r_(0),
    g_(0),
    b_(0)
{
    switch (color)
    {
    case WHITE:     r_ = 255; g_ = 255; b_ = 255; break;
    case RED:       r_ = 255;           break;
    case GREEN:     g_ = 255;           break;
    case BLUE:      b_ = 255;           break;
    case YELLOW:    r_ = 255; g_ = 255; break;
    case CYAN:      g_ = 255; b_ = 255; break;
    case MAGENTA:   r_ = 255; b_ = 255; break;
    case GRAY_LIGHT:r_ = g_ = b_ = 211; break;
    case GRAY:      r_ = g_ = b_ = 128; break;
    case GRAY_DARK: r_ = g_ = b_ = 64; break;
    case ORANGE:    r_ = 255; g_=165;b_=0; break;
    case BROWN:     r_ = 138; g_=42;b_=42; break;

    default: ;
    }
}

//=============================================================================
Color Color::read(const char* color)
{
    string c(color);
    EPredef C = BLACK;

    if      (c == "white")   C = WHITE;
    else if (c == "red")     C = RED;
    else if (c == "green")   C = GREEN;
    else if (c == "blue")    C = BLUE;
    else if (c == "yellow")  C = YELLOW;
    else if (c == "cyan")    C = CYAN;
    else if (c == "magenta") C = MAGENTA;
    else if (c == "gray")    C = GRAY;
    else if (c == "lgray")   C = GRAY_LIGHT;
    else if (c == "dgray")   C = GRAY_DARK;
    else if (c == "orange")  C = ORANGE;
    else if (c == "brown")   C = BROWN;
    else {
        vector<string> strings;
        istringstream f(color);
        string s;
        while (getline(f, s, ',')) {
            strings.push_back(s);
        }

        if ( strings.size() == 3) {
            int r = stoi(strings.at(0));
            int g = stoi(strings.at(1));
            int b = stoi(strings.at(2));

            return Color(r, g, b);
        }
    }

    return Color(C);
}

//=============================================================================
Color Color::supplement() const
{
    return Color(255-r_, 255-g_, 255-b_);
}

//=============================================================================
Color& Color::add(int value)
{
    int r = r_ + value;
    int g = g_ + value;
    int b = b_ + value;

    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;

    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    r_ = r;
    g_ = g;
    b_ = b;

    return *this;
}

//=============================================================================
double Color::distanceSq(const Color& c1, const Color& c2)
{
    double dr = c1.rf()-c2.rf();
    double dg = c1.gf()-c2.gf();
    double db = c1.bf()-c2.bf();

    return dr*dr+dg*dg+db*db;
}

//=============================================================================
std::string Color::write() const
{
    char buffer[100];
    sprintf(buffer, "%d,%d,%d", r(), g(), b());
    return buffer;
}

//=============================================================================
