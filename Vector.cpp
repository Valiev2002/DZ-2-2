#include "Vector.h"
template<class T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this != &other)
    {
        if (_capacity != other._capacity)
        {
            delete[] array;
            _capacity = other._capacity;
            _size = other._size;
            array = new int[_capacity + 1];
        }

        for (int i = 0; i < _size; ++i)
            array[i] = other.array[i];
    }

    return *this;
}

template<class T>
void Vector<T>::push_back(int &&element) {
    if (_capacity < _size)
    {
        if (_capacity == 1)
            reserve(2);
        else
            reserve(1.5 * _size);
    }
    _size++;
    array[_size - 1] = element;

}

template<class T>
void Vector<T>::resize(int real_size) {
    int* temp = new int[real_size + 1];

    if (real_size < _size)
    {
        _size = real_size;
    }
    else
    {
        for (int i = 0; i < _size; ++i)
            temp[i] = array[i];
        for (int i = _size; i < real_size; ++i)
            temp[i] = 0;
        _size = real_size;
    }
    array = temp;

}

template<class T>
void Vector<T>::swap(Vector &other) {
    Vector<T> temp = *this;
    *this = other;
    other = temp;

}

template<class T>
void Vector<T>::reserve(int num) {
    if (num > _capacity)
    {
        _capacity = num;

        int* temp = new int[_capacity + 1];

        for (int i = 0; i < _size; ++i)
            temp[i] = array[i];

        delete[] array;
        array = temp;
    }
}

template<class T>
Iterator<T> Vector<T>::insert(const Iterator<T> &it, int &&element) {
    if (_capacity > _size)
    {
        int rast = std::distance(begin(), it);

        for (int i = _size; i > rast; i--)
            array[i] = array[i - 1];

        *it = element;
        return it;
    }
    else
    {
        int rast = std::distance(begin(), it);

        reserve(2.0 * _capacity);

        for (size_t i = _size; i > rast; i--)
            array[i] = array[i - 1];

        *(begin() + rast) = element;

            return begin() + rast;
    }

}

template<class T>
Iterator<T> Vector<T>::erase(const Iterator<T> &it) {
    int rast = std::distance(begin(), it);
    for (int i = rast; i < _size - 1; i++)
        array[i] = array[i + 1];
    _size--;
    return begin() + rast;
}

template<class T>
Iterator<T> Vector<T>::erase(const Iterator<T> &left, const Iterator<T> &right) {
    int rast_f = std::distance(begin(), left);
    int rast_l = std::distance(begin(), right);
    int rast = rast_l - rast_f + 1;

    for (int i = rast_f; i < rast_l + 1; i++)
        array[i] = array[i + rast];

    if (rast_l > _size - 1)
        _size = _size - rast + 1;
    else
        _size -= rast;
    return begin() + rast;
}

