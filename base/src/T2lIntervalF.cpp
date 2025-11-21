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
#include "T2lIntervalF.h"

using namespace T2l;

//=============================================================================
double IntervalF::mapValue(double oldValue, const IntervalF& oldInterval, const IntervalF& newInterval)
{
    double d_o = oldValue-oldInterval.beg();

    double d_n = ( d_o * newInterval.getLength() ) / oldInterval.getLength();
    double newValue = newInterval.beg() + d_n;

    return newValue;
}

//=============================================================================
