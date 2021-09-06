#include<iostream>
#include<algorithm>
#include"Iterator.h"
#include"Const_Iterator.h"
#include"Const_Reverse_Iterator.h"


#pragma once
template<class T>
    class Vector
    {
        T* array;
        int _size;
        int _capacity;

    public:
        Vector() : _size(0), _capacity(0)
        {
            array = new int[1];
        };
        void print()
        {
            for (int i : *this)
                std::cout << i << ' ';
            std::cout << std::endl;
        }
        int size() const { return _size; };
        int  length() const { return _size; };
        int capacity() const { return _capacity - 1; };

        ~Vector()= default;
        Vector<T>& operator=(const Vector<T>& other); // присваивание копированием
        Iterator<T> begin() const { return Iterator<T>(&array[0]); };
        Const_Iterator<T> cbegin()const noexcept    { return Const_Iterator<T>(&array[1]);};
        //Reverse_Iterator<T> rbegin() noexcept{ return Reverse_Iterator<T>(&array[_size]);};
        Const_Reverse_Iterator<T> crbegin() const noexcept{return Const_Reverse_Iterator<T>(&array[_size]);};

        Iterator<T> end() const { return Iterator<T>(&array[_size]); };
        Const_Iterator<T> cend()const noexcept	{ return Const_Iterator<T>(&array[_size + 1]);};
        //Reverse_Iterator<T> rend() noexcept{ return Reverse_Iterator<T>(&array[0]);};
        Const_Reverse_Iterator<T> crend()const noexcept{ return Const_Reverse_Iterator<T>(&array[0]);};

        int at(int index)
        {
            if ((index < _size) && (index >= 0))
                return array[index];
            else
                throw std::out_of_range("Out of range");
        }

        int& operator[](int index) { return array[index]; };

        int& front() { return array[0]; };
        int& back() { return array[_size-1]; };

        int* data() { return array; };

        bool empty() const
        {
            if (_size == 0)
                return true;
            else
                return false;
        }

        void reserve(int num);

        void clear()
        {
            delete[] array;
        _size = 0;

            array = new int[1];
        }

        Iterator<T> insert(const Iterator<T>& it, int&& element);

        Iterator<T> erase(const Iterator<T>& it);
        Iterator<T> erase(const Iterator<T>& left, const Iterator<T>& right);

        void push_back(int&& element);
        void pop_back() { _size--; };

        void resize(int real_size);
        void swap(Vector& other);
    };


