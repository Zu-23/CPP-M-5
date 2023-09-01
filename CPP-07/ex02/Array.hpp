#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

class Boundlimit: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Array index out of bound");
	}
};

template<typename T>
class Array
{
	private:
		T				*array;
		unsigned int	n;
	public:
		Array(void) : n(0), array(NULL)
		{
			std::cout << "default constrcutor called" << std::endl;
		}
		Array(unsigned int n) : n(n)
		{
			std::cout << "Array created" << std::endl;
			this->array = new T[n];
		}

		~Array()
		{
			delete [] array;
			std::cout << "Destructor is called"<< std::endl;
		}

		Array(const Array<T> &obj) : array(NULL)
		{
			unsigned int size = obj.size();
			this->n = size;
			if (obj.array)
			{
				this->array = new T[size];
				for (unsigned int i = 0; i < size; i++)
				{
					this->array[i] = obj.array[i];
				}
			}
		}

		Array	&operator=(const Array<T> &obj)
		{
			if (this != &obj)
			{
				delete[] array;
				this->n = obj.n;
				array = new T[this->n];
				for (unsigned int i = 0; i < n; i++)
				{
					array[i] = obj.array[i];
            	}
        	}
        	return *this;
		}

		T & operator[](unsigned int i) const
		{
			if (i > this->size())
				throw (Boundlimit());
			return this->array[i];
		}

		unsigned int size() const
		{
			return this->n;
		}
};

#endif