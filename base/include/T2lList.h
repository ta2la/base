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

#include "T2lListClever.h"

namespace T2l {

//=============================================================================
template <class T>
class List {
//=============================================================================
public:
// <CONSTRUCTION>
    List() {}
    virtual ~List() {}
// <METHODS>
    virtual void add(T* item);
    virtual void insert(T* item, int index) { items_.insert(item, index); }
    virtual int count() const { return items_.count(); }
    virtual T*  get(int index);
    virtual T* const get2(int index) const;
    virtual T* last();
    virtual void removeIndex( int index) { items_.removeIndex(index); }
    virtual void remove( T* item ) { items_.remove(item); }
    virtual void clean() { items_.clean(); }
    virtual void set(int index, T* item);
//=============================================================================
protected:
// <DATA>
    ListClever<T*> items_;
};

template <class T>
void List<T>::add(T* item)
{
    items_.add(item);
}

template <class T>
T* List<T>::get(int index)
{
    if (index < 0) return nullptr;
    if (index >= count()) return nullptr;
    return items_.get(index);
}

template <class T>
T* const List<T>::get2(int index) const
{
    if (index < 0) return nullptr;
    if (index >= count()) return nullptr;
    return items_.get2(index);
}

template <class T>
T* List<T>::last()
{
    if (count()==0) return nullptr;
    return get(count()-1);
}

template <class T>
void List<T>::set(int index, T* item)
{
    items_.get(index) = item;
}

} // namespace t2l
