//
//  vector.hpp
//  vector
//
//  Created by Сурков Дмитрий Валерьевич on 16.03.2018.
//  Copyright © 2018 Сурков Дмитрий Валерьевич. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class vector_t
{
private:
    T * elements_;
    std::size_t size_;
    std::size_t capacity_;
public:
    vector_t();
    vector_t(vector_t const & other);
    vector_t & operator =(vector_t const & other);
    ~vector_t();
    
    std::size_t size() const;
    std::size_t capacity() const;
    
    void push_back(int value);
    void pop_back();
    T at(std::size_t index);
    T & at(std::size_t index) const;
    T & operator [](std::size_t index);
    T operator [](std::size_t index) const;
    
    bool operator ==(vector_t const & other) const;
};

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs);

template <typename T>
vector_t<T>::vector_t() : size_{ 0 }, capacity_{ 0 }, elements_{ nullptr }
{}

template <typename T>
vector_t<T>::vector_t(vector_t const & other)
{
    elements_ = new T[other.capacity_];
    for (std::size_t i = 0; i < other.size_; i++)
    {
        elements_[i] = other.elements_[i];
    }
    capacity_ = other.capacity_;
    size_ = other.size_;
}

template <typename T>
T vector_t<T>::at(std::size_t index)
{
    if (index >= size_){
        try {
            return elements_ [index];
        }
        catch (...) {
            std::cout << "Index is out of current vector" << std::endl;
        }
    }
    return elements_[index];
}

template <typename T>
T & vector_t<T>::at(std::size_t index) const
{
    if (index >= size_){
        try {
            return elements_ [index];
        }
        catch (...) {
            std::cout << "Index is out of current vector" << std::endl;
        }
    }
    return elements_[index];
}

template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{
    if(this != &other)
    {
        if(elements_ != nullptr)
        {
            delete[] elements_;
        }
        capacity_ = other.capacity_;
        size_ = other.size_;
        elements_ = new T[other.capacity_];
        for (std::size_t i = 0; i < other.capacity_; i++)
        {
            elements_[i] = other.elements_[i];
        }
    }
    return *this;
}

template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
    bool flag = size_ == other.size_;
    if (flag)
    {
        for (std::size_t i = 0; i < size_; i++)
        {
            if (elements_[i] != other.elements_[i])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

template <typename T>
vector_t<T>::~vector_t()
{
    if (elements_ != nullptr)
    {
        delete[] elements_;
    }
}

template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}

template <typename T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}

template <typename T>
void vector_t<T>::push_back(int value)
{
    if (capacity_)
    {
        if (size_ == capacity_)
        {
            capacity_ *= 2;
            T * temp = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i)
            {
                temp[i] = elements_[i];
            }
            delete[] elements_;
            elements_ = temp;
        }
    }
    else
    {
        capacity_ = 1;
        elements_ = new T[capacity_];
    }
    elements_[size_++] = value;
}

template <typename T>
void vector_t<T>::pop_back()
{
    if (size_)
    {
        --size_;
        if (size_ <= (capacity_/4))
        {
            capacity_ = capacity_ / 2;
            T *temp = new T[capacity_];
            for (int i = 0; i < size_; i++)
            {
                temp[i] = elements_[i];
            }
            delete[] elements_;
            elements_ = temp;
        }
    }
    else
    {
        std::cout << "Vector is empty! Error!\n";
    }
}

template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
    return elements_[index];
}

template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
    return elements_[index];
}

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
    return  !(lhs == rhs);
}



#endif /* vector_hpp */
