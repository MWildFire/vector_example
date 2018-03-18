#include "vector.hpp"
#include <algorithm>
#include <cassert>



vector_t::vector_t() : size_{ 0 }, capacity_{ 0 }, elements_{ nullptr }
{
    
}

vector_t::vector_t(vector_t const & other)
{
    elements_ = new int[other.capacity_()];
    for (std::size_t i = 0; i < other.size_(); i++)
    {
        elements_[i] = other.elements_[i];
    }
    capacity_ = other.capacity_();
    size_ = other.size_();
}


vector_t::~vector_t()
{
    if (elements_ != nullptr)
    {
    	delete[] elements_;
    }
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}


vector_t & vector_t::operator =(vector_t const & other) {
	
	if (this != &other) 
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		elements_ = new int[other.capacity_];
		for (std::size_t i = 0; i < other.capacity_; i++) 
		{
			elements_[i] = other.elements_[i];
		}

	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const 
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

void vector_t::push_back(int value) 
{
	if (capacity_) 
        {
		if (size_ == capacity_) 
                {
			capacity_ *= 2;
			int * temp = new int[capacity_];
			for (std::size_t i = 0; i < size_; ++i) 
                        {
				temp[i] = elements_[i];
			}
			
			delete[] elements_;
			elements_ = temp;
		}
	} else 
        {
		capacity_ = 1;
		int * elements_ = new int[capacity_];
	}
	elements_[size_++] = value; 
}


void vector_t::pop_back() 
{
	if (size_) 
        {
		if (capacity_ == size_ / 2) 
        	{
			capacity_ = capacity_ / 2;
			int *temp = new int[capacity_];
			for (int i; i < size_; i++) 
            		{
				temp[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = temp;
		}

		--size_;
	} else 
    	{
		std::cout << "Vector is empty! Error!\n";
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
