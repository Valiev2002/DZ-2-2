#include <iterator>
#pragma once

template <class T>
class Const_Iterator
{
    T* pos;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = const T;
    using difference_type = int;
    using pointer = const T*;
    using reference = const T&;

    Const_Iterator(T* position) : pos(position) { };

    bool operator==(const Const_Iterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const Const_Iterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    Const_Iterator& operator++()
    {
        ++pos;
        return *this;
    };

    Const_Iterator& operator++(int)
    {
        ::Const_Iterator<T> temp = *this;
        ++pos;
        return temp;
    };

    Const_Iterator& operator--()
    {
        --pos;
        return *this;
    };

    Const_Iterator& operator--(int)
    {
        Const_Iterator<T> temp = *this;
        --pos;
        return temp;
    };
};