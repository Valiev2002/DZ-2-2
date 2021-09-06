#include <iterator>

#pragma once

template <class T>
class Reverse_Iterator
{
    T* pos;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    Reverse_Iterator(T* position) : pos(position) { };

    bool operator==(const Reverse_Iterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const Reverse_Iterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    Reverse_Iterator& operator++()
    {
        --pos;
        return *this;
    };

    Reverse_Iterator& operator++(int)
    {
        Reverse_Iterator<T> temp = *this;
        --pos;
        return temp;
    };

    Reverse_Iterator& operator--()
    {
        ++pos;
        return *this;
    };

    Reverse_Iterator<T>  operator--(int)
    {
        Reverse_Iterator<T> temp = *this;
        ++pos;
        return temp;
    };

    reference operator[](size_t index) const { return pos[index]; };

    Reverse_Iterator operator+(const difference_type& diff) const { return Reverse_Iterator<T>(pos - diff); };
    friend inline Reverse_Iterator operator+(const difference_type& diff, const Reverse_Iterator<T>& other)
    {
        return Reverse_Iterator<T>(other.pos - diff);
    };

    Reverse_Iterator<T> operator-(const difference_type& diff) const { return Reverse_Iterator<T>(pos + diff); };
    difference_type operator-(const Reverse_Iterator<T>& other) const { return std::distance(other.pos, pos); };

    Reverse_Iterator<T> operator+=(const difference_type& diff)
    {
        pos -= diff;
        return *this;
    };

    Reverse_Iterator<T> operator-=(const difference_type& diff)
    {
        pos += diff;
        return *this;
    };
};
