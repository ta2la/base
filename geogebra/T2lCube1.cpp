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
#include "T2lCube1.h"
#include "T2lBox.h"
#include "T2lPlane3.h"
#include "T2lArea2.h"
#include "T2lRay3.h"

#include <assert.h>

using namespace T2l;
using namespace std;

//=============================================================================
Cube1::Cube1(const Point3I& p3) :
    point_(p3)
{
}

//=============================================================================
bool Cube1::isInside(const Point3F& point)
{
    Box<double, 3> box;
    box.inflateTo(pointLower());
    box.inflateTo(pointDelta(Point3F(1,1,1)));

    return box.isInside(point);
}

//=============================================================================
Point3F Cube1::pointGet(int index)
{
    switch(index) {
    case 0: return pointDelta(Point3F(0,0,0));
    case 1: return pointDelta(Point3F(1,0,0));
    case 2: return pointDelta(Point3F(1,1,0));
    case 3: return pointDelta(Point3F(0,1,0));

    case 4: return pointDelta(Point3F(0,0,1));
    case 5: return pointDelta(Point3F(1,0,1));
    case 6: return pointDelta(Point3F(1,1,1));
    case 7: return pointDelta(Point3F(0,1,1));
    }

    assert(0);
    return pointDelta(Point3F(0,0,0));
}

//=============================================================================
pair<Point3F, Point3F> Cube1::verticeGet(int index)
{
    switch(index) {
    case 0: return make_pair( pointGet(0), pointGet(1) );
    case 1: return make_pair( pointGet(1), pointGet(2) );
    case 2: return make_pair( pointGet(2), pointGet(3) );
    case 3: return make_pair( pointGet(3), pointGet(0) );

    case 4: return make_pair( pointGet(4), pointGet(5) );
    case 5: return make_pair( pointGet(5), pointGet(6) );
    case 6: return make_pair( pointGet(6), pointGet(7) );
    case 7: return make_pair( pointGet(7), pointGet(4) );

    case 8:  return make_pair( pointGet(0), pointGet(4) );
    case 9:  return make_pair( pointGet(1), pointGet(5) );
    case 10: return make_pair( pointGet(2), pointGet(6) );
    case 11: return make_pair( pointGet(3), pointGet(7) );
    }

    assert(0);
    return make_pair( pointGet(0), pointGet(1) );
}

//=============================================================================
std::array<int, 4> Cube1::faceIndexes(int index)
{
    switch (index) {
    case 0: return { 0, 1, 2, 3};
    case 1: return { 0, 1, 5, 4};
    case 2: return { 1, 2, 6, 5};
    case 3: return { 2, 3, 7, 6};
    case 4: return { 3, 0, 4, 7};
    case 5: return { 4, 5, 6, 7};
    }

    return { 0, 1, 2, 3};
}

//=============================================================================
pair<int, double> Cube1::nearestFace(const Ray3& ray)
{
    int result = -1;
    double distance = std::numeric_limits<double>::max();

    for (int i = 0; i < faceCount(); i++) {
        std::array<int, 4> fi = faceIndexes(i);
        Plane3 plane(pointGet(fi[0]), pointGet(fi[1]), pointGet(fi[2]));
        Area2 area2;

        std::optional<Point3F> pSect = ray.getIntersect(plane);
        if (!pSect.has_value()) continue;

        Point3F pSectP = plane.projectPerpend(*pSect);
        Point2F pSect2 = plane.uv(pSectP);

        std::array<int, 4> indexes = faceIndexes(i);

        for (int j = 0; j < 4; j++) {
            Point3F pt3 = plane.projectPerpend(pointGet(indexes[j]));
            area2.points().points().add(plane.uv(pt3));
        }

        if(!area2.isInside(pSect2)) continue;
        double distancei = Vector3F(ray.getPoint(0.0), *pSect).getLength();
        if (distancei > distance) continue;

        result = i;
        distance = distancei;
    }

    return {result, distance};
}

//=============================================================================
