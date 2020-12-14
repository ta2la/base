//
// Copyright (C) 2016 Petr Talla. [petr.talla@gmail.com]
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
#include <T2lNaray2vec.h>
#include <iostream>
#include <random>

using namespace T2l;
using namespace std;

//=============================================================================
Naray2vec::Naray2vec( int d0, int d1 ) : Naray2( d0, d1 )
{
}

//=============================================================================
Point2I Naray2vec::calculateBmatch(const ColumnF& c)
{
    int X = 0;
    int Y = 0;

    double diff = ColumnF::diffSq(get(0, 0), c);

    for (int ix = 0; ix < countX(); ix++) {
        for (int iy = 0; iy < countY(); iy++) {

            double erri = ColumnF::diffSq(get(ix, iy), c);
            if (erri > diff) continue;

            X = ix;
            Y = iy;
            diff = erri;
        }
    }

    return Point2I(X, Y);
}

//=============================================================================
Point2I Naray2vec::calculateBmatch(const ColumnF& cc, const ColumnF& minima, const ColumnF& maxima, const ColumnF& importance)
{
    int X = 0;
    int Y = 0;

    ColumnF c   = normalize(cc, 100, minima, maxima);

    ColumnF c00 = normalize(get(0, 0), 100, minima, maxima);
    double diff = ColumnF::diffSqImportance(c00, c, importance);

    for (int ix = 0; ix < countX(); ix++) {
        for (int iy = 0; iy < countY(); iy++) {

            ColumnF cxy = normalize(get(ix, iy), 100, minima, maxima);
            double erri = ColumnF::diffSqImportance(cxy, c, importance);
            if (erri > diff) continue;

            X = ix;
            Y = iy;
            diff = erri;
        }
    }

    return Point2I(X, Y);
}

//=============================================================================
double Naray2vec::calculateDistance(const Point2I& p0, const Point2I& p1)
{
    double dx = p0.x() -p1.x();
    double dy = p0.y() -p1.y();

    return sqrt(dx*dx+dy*dy);
}

//=============================================================================
double Naray2vec::normalize(double value, double range, double minima, double maxima)
{
    return range*(value-minima)/(maxima-minima);
}

//=============================================================================
ColumnF Naray2vec::normalize(const ColumnF& column, double range, const ColumnF& minima, const ColumnF& maxima)
{
    ColumnF result(column.count());

    for (int i = 0; i < column.count(); i++) {
        result.get(i) = normalize(column.get(i), range, minima.get(i), maxima.get(i));
    }

    return result;
}

//=============================================================================
void Naray2vec::initializeRandom(const ColumnF min, const ColumnF max)
{
    random_device rd;
    mt19937 gen(rd());

    for (int ix = 0; ix < countX(); ix++) {
        for (int iy = 0; iy < countY(); iy++) {
            ColumnF c(get(ix,iy).count());

            for ( int i = 0; i < c.count(); i++) {
                uniform_real_distribution<> dis(min.get(i), max.get(i));
                get(ix, iy).get(i) = dis(gen);
            }
        }
    }
}

//=============================================================================
