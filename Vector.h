#pragma once

#include <iostream>
#include <cassert>
using namespace std;

template <class t>
class Vector
{
	t* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 15;
public:
	Vector()
	{
		_array = new t[_capacity];

	}
	Vector(int capacity)
	{
		while (_capacity <= capacity)
			_capacity += 16;
		_array = new t[_capacity];
	}

	inline t* GetData() const { return this->_array; }
	inline size_t GetSize()const { return this->_size; }
	inline size_t GetCapacity()const { return this->_capacity; }


	t& operator[](size_t index) { return this->_array[index]; }

	Vector& pushBack(const t item)
	{
		Vector nevvec;

		nevvec._array = new t[nevvec._sizesize + 1];
		for (size_t i = 0; i < _size; i++)
			nevvec._array[i] = this->_array[i];

		nevvec._array[_size + 1] = item;

		return nevvec;
	}
	Vector& pushFront(const t item)
	{
		Vector nevvec;
		nevvec._size = size + 1;
		nevvec._array = new t[nevvec._size_size];
		for (size_t i = 0; i < _size; i++)
			nevvec._array[i + 1] = this->_array[i];

		nevvec._array[0] = item;

		return nevvec;
	}

	void push_back(int item)
	{
		if (_size < _capacity)
		{
			_array[_size] = item;
			_size++;
			return;
		}

		_capacity *= 2;
		int* temp = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];

		temp[_size] = item;
		_size++;

		delete[] _array;
		_array = temp;
	}
	void push_front(int item)
	{
		if (_size == _capacity)
		{
			_capacity *= 2;
			int* temp = new int[_capacity];
			temp[0] = item;

			for (size_t i = 0; i < _size; i++)
				temp[i + 1] = _array[i];
			_size++;

			delete[] _array;
			_array = temp;
			return;
		}

		for (size_t i = _size; i > 0; i--)
			_array[i] = _array[i - 1];
		_array[0] = item;
		_size++;
	}

	void delete_by_index(const size_t index)
	{
		if (index < _size)
		{
			for (size_t i = 0; i < index; i++)
			{
				this->_array[i] = _array[i];
			}
			for (size_t i = index + 1; i < _size; i++)
			{
				this->_array[i - 1] = this->_array[i];
			}
			_size--;
		}
		else
			assert(!"out of length");
		
	}
	void insert_by_index(const size_t index, const t element)
	{
		if (index < _size)
		{
			t* newarr = new t[_size + 1];
			for (size_t i = 0; i < index; i++)
			{
				newarr[i] = _array[i];
			}
			newarr[index] = element;
			for (size_t i = index+1; i < _size; i++)
			{
				newarr[i] = _array[i];
			}
			_size++;
			delete[] _ara
		}
	}
	size_t find(const t element)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_array[i] == element)
				return i;
		}
		assert(!"Not found");
	}
	size_t rfind(const int element)
	{
		for (size_t i = _size - 1; i > 0; i++)
		{
			if (_array[i] == element)
				return i;
		}
		assert(!"Not found");
	}
	void sort(bool reverse = false)
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = i + 1; j < _size; j++)
			{
				if (reverse == false ? _array[i] < _array[j] : _array[i] > _array[j])
				{
					int temp = _array[i];
					_array[i] = _array[j];
					_array[j] = temp;
				}
			}
		}
	}

	template <class t>
	friend ostream& operator<<(ostream& print, const Vector<t>& v1);

	template <class t>
	friend istream& operator>>(istream& input, Vector<t>& v1);
};


template <class t>
ostream& operator<<(ostream& print, const Vector<t>& v1)
{
	print << "=============================" << endl;
	for (size_t i = 0; i < v1._size; i++)
		print << v1._array << endl;
	print << "=============================" << endl;
	return print;
}

template <class t>
istream& operator>>(istream& input, Vector<t>& v1)
{
	cout << "Enter array's size: "; input >> v1._size;
	cout << "Enter array's capacity"; input >> v1._capacity;

	for (size_t i = 0; i < v1._size; i++)
	{
		t* element;
		input >> element;
		v1._array[i] = element;

	}
	return input;
}
