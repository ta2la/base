//
// Copyright (C) 2019 Petr Talla. [petr.talla@gmail.com]
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
#include "T2lRectSpiral2.h"

using namespace T2l;

//=============================================================================
RectSpiral2::RectSpiral2() :
    index_(0),
    progress_(1, 0),
    current_(0, 0)
{
}

//=============================================================================
void RectSpiral2::next()
{
    bool rotate = false;

    if (current_.x()>=0 && current_.y()>=0) {
        if ( abs(current_.x())-1 == abs(current().y()) ) rotate = true;
    }
    else if ( abs(current_.x()) == abs(current().y()) ) {
        rotate = true;
    }

    if (rotate) {
        progress_.setPerpendLeft();
        progress_.multiply(-1);
    }

    current_.add(progress_);
    index_++;
}

//=============================================================================
