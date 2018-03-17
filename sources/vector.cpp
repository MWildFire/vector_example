#include "vector.hpp"
#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() : size_{ 0 }, capacity_{ 0 }, elements_{ nullptr }
{
    
}

vector_t::vector_t(vector_t const & other)
{
    elements_ = new int[capacity_];
    for (std::size_t i = 0; i < size_; i++)
    {
        elements_[i] = other.elements_[i];
    }
    capacity_ = other.capacity_;
    size_ = other.size_;
}

vector_t & vector_t::operator =(vector_t const & other)
{
    elements_ = new int[other.capacity_];
    for (std::size_t i = 0; i<other.capacity_; i++)
    {
        elements_[i] = other.elements_[i];
    }
    capacity_ = other.capacity_;
    size_ = other.size_;
    return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
    bool result = true;
    if (size_ != other.size_)
    {
        return false;
    }
    else for (std::size_t i = 0; i < other.size_; i++)
    {
        if (elements_[i] != other.elements_[i])
        {
            result = false;
        }
        else
            result = true;
    }
    return result;
}

vector_t::~vector_t()
{
    delete []elements_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
    if(size_<capacity_)
    {
        size_++;
        elements_[size_-1] = value;
    }
    else if (size_ == capacity_)
    {
        capacity_ *= 2;
        size_++;
        int *temp = new int[size_-1];
        for (std::size_t i = 0; i < size_-1; ++i)
        {
            temp[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = new int[capacity_];
        for (std::size_t i = 0; i < size_; ++i)
        {
            if( i != size_-1) elements_[i] = temp[i];
            else elements_[i] = value;
        }
        delete[] temp;
    }
}

void vector_t::pop_back()
{
    size_ --;
    if (size_ <= (capacity_ / 4))
    {
        capacity_ = capacity_ / 2;
        int *elements = new int[capacity_];
        for (int i; i<size_; i++)
        {
            elements[i] = elements_[i];
        }
        
        if (elements_ != nullptr)
        {
            delete[] elements_;
        }
        elements_ = elements;
    }
}

int & vector_t::operator [](std::size_t index)
{
    return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
    return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
    return  !(lhs == rhs);
}
