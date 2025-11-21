//
// Copyright (C) 2013-2021 Petr Talla. [petr.talla@gmail.com]
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

namespace T2l

{

#define T2L_EPS 1e-9

enum Side {
    LEFT      = 0x00000001,
    RIGHT     = 0x00000010,
    TOP       = 0x00000100,
    BOTTOM    = 0x00001000,
    ALL       = 0x00001111
};

#define TATTR_SIMPLE(TYPE,NAME) protected: TYPE NAME##_;  \
                                public: TYPE NAME()    {return NAME##_;} void NAME##Set(TYPE NAME) {NAME##_ = NAME;}
#define TATTR_SIMPLE_EX(TYPE,NAME,VALUE) protected: TYPE NAME##_ = {VALUE};  \
                                public: TYPE NAME()    {return NAME##_;} void NAME##Set(TYPE NAME) {NAME##_ = NAME;}
#define TATTR_OBJECT(TYPE,NAME) protected: TYPE NAME##_;  public: const TYPE & NAME() const {return NAME##_;} void NAME##Set(const TYPE & NAME) {NAME##_ = NAME;}
#define TATTR_NEIGHB(TYPE,NAME) protected: TYPE* NAME##_; public: TYPE##& NAME() {return *NAME##_;}

}

#define PIMPL struct Impl; Impl* pimpl_;
