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
#include "T2lStationing2.h"
#include "T2lAngle.h"

using namespace T2l;

//=============================================================================
Stationing2::Stationing2()
{
}

//===================================================================
double Stationing2::parameterOffset(PolyLine2& pline, double parameter, double offset)
{
    if ( ( offset <= 10e-9 ) || ( pline.points().count() < 2 ) ) return parameter;
    if ( parameter > pline.paramMax() ) return pline.paramMax();

    long vertex = pline.vertex(parameter);

    double paramDelta = offset/Vector2F(pline.points().get(vertex), pline.points().get(vertex+1)).getLength();
    if ( paramDelta <= ((double)(long)parameter+1.0)-parameter ) {
        return parameter + paramDelta;
    }
    else {
        if ( vertex == pline.paramMax()) return pline.paramMax();
        double parameterNext = (long)parameter+1.0;
        double distanceNext = offset-Vector2F(pline.getPoint(parameter), pline.points().get(vertex+1)).getLength();
        if ( distanceNext < 10e-9 ) return parameterNext;
        return parameterOffset(pline, parameterNext, distanceNext);
    }

}

//===================================================================
void Stationing2::cutPart(PolyLine2& source, PolyLine2& result, double parameterBeg, double parameterEnd)
{   assert(parameterBeg >= 0);
    if ( parameterEnd > source.paramMax() ) parameterEnd = source.paramMax();
    assert ( parameterBeg <= parameterEnd );

    result.points().add(source.getPoint(parameterBeg));
    for ( long i = parameterBeg+1; i < parameterEnd+1; i++ ) {
        result.points().add(source.points().get(i));
    }
    result.points().add(source.getPoint(parameterEnd));
}

//=============================================================================
