//
// Copyright (C) 2020 Petr Talla. [petr.talla@gmail.com]
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

#include <list>

namespace T2l {

//=============================================================================
template <class T>
class ListClever {
//=============================================================================
public:
// <CONSTRUCTION>
    ListClever();
    virtual ~ListClever() {*current_;}
// <METHODS>
    void add(const T& item)    { items_.push_back(item); }
    int  count() const  { return items_.size(); }
    T&   get(int index)   { prepareIndex_(index); return const_cast<T&>(*current_); }
    const T& get2(int index) const { prepareIndex_(index); return const_cast<T&>(*current_); }
    T&   last()          { return *(--items_.end()); }
    T&   first()         { return *(items_.begin()); }
    void removeIndex( int index);
    void remove( T item) { items_.remove(item); currentIndex_ = -1; }
    void removeFirst()   { items_.pop_front(); currentIndex_ = -1; }
    void clean()         { items_.clear(); currentIndex_ = -1; }
    void insert(const T& item, int index);
//=============================================================================
protected:
// <DATA>
    void prepareIndex_(int index) const;

    std::list<T>           items_;

    typedef typename std::list<T>::const_iterator Iterator;
    mutable Iterator       current_;
    mutable int            currentIndex_;
};

template <class T>
ListClever<T>::ListClever() :
    currentIndex_(-1)
{
}

template <class T>
void ListClever<T>::insert(const T& item, int index)
{
    get(index);
    items_.insert(current_, item);
    currentIndex_ = -1;
}

template <class T>
void ListClever<T>::prepareIndex_(int index) const
{
    if ( index == 0 ) {
        current_ = items_.begin();
        currentIndex_ = 0;
    }

    if ( currentIndex_>=0 && index==currentIndex_+1 ) {
        current_++;
        currentIndex_++;
        return;
    }
    if ( currentIndex_>=0 && index==currentIndex_-1 ) {
        current_--;
        currentIndex_--;
        return;
    }

    current_ = items_.begin();
    currentIndex_ = 0;

    while(currentIndex_ != index) {
        current_++;
        currentIndex_++;
    }
}

template <class T>
void ListClever<T>::removeIndex(int index)
{
    prepareIndex_(index);
    Iterator current = current_;

    if ( count()<4 || index<2) {
        currentIndex_ = -1;
    }
    else {
        current_--;
        currentIndex_--;
    }

    items_.erase(current);
}

} // namespace t2l
