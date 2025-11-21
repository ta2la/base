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

#include "T2lList.h"
#include "T2lItemParent.h"

namespace T2l {

//=============================================================================
template <class T>
class ItemCol : public List<T>, public ItemParent {
//=============================================================================
public:
// <CONSTRUCTION>
    ItemCol() = default;
    virtual ~ItemCol() { clean(); }
// <METHODS>
    virtual void add(T* item);
    virtual void remove( int index);
    virtual void remove( T* item );
    virtual void clean();
//=============================================================================
//<OVERRIDES>
    virtual void release_child_ ( Item* item );
protected:
// <DATA>
};

//=============================================================================
template <class T>
void ItemCol<T>::add(T* item )
{
    add_child_(item);
    List<T>::items_.add(item);
}

//=============================================================================
template <class T>
void ItemCol<T>::remove( int index )
{
    T* item = List<T>::items_.get(index);
    remove(item);
}

//=============================================================================
template <class T>
void ItemCol<T>::remove( T* item )
{
    //item->parent_ = nullptr;
    set_parent_null_(item);
    List<T>::items_.remove(item);
}

//=============================================================================
template <class T>
void ItemCol<T>::clean()
{
    while (List<T>::count() > 0) {
        Item* item = List<T>::items_.first();
        List<T>::items_.removeFirst();
        delete item;
    }
}

//=============================================================================
template <class T>
void ItemCol<T>::release_child_ ( Item* item )
{
    List<T>::items_.remove((T*)item);
}

} // namespace t2l
