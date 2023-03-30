#ifndef iostream
#include <iostream>
#endif
template <class data_type>
class vector
{
private:
	int Capacity = 0, count = 0; // capacity is capacity of element can store and count is the no. of element stored in vector
	int type = 0;				 // type for which index of pointer a using
	data_type *ptr[2];			 // two pointer for storing and deleting and creating new,so on......
	void increase()
	{
		type ? type = 0 : type = 1;					// changing type because we are going to use another pointer for vector
		(!Capacity) ? Capacity = 1 : Capacity *= 2; // increasing capacity
		ptr[type] = new data_type[Capacity];		// allocating memory for vector
		int temp = (type) ? 0 : 1;					// precious vector to copy it element
		for (int i = 0; i < Capacity / 2; i++)		// copying element
		{
			ptr[type][i] = ptr[temp][i];
		}
		delete[] ptr[temp]; // deleting previous vector
		ptr[temp] = NULL;	// assigning NULL to previous vector
	}

public:
	vector() // if no size is given then assiging both pointer to NULL
	{
		ptr[0] = NULL;
		ptr[1] = NULL;
	}
	vector(int size) // if any size is given then creating a vector of that size
	{
		Capacity = size;
		ptr[0] = new data_type[Capacity];
		ptr[1] = NULL;
	}
	int size() { return count; }		// returning size of the vector
	int capacity() { return Capacity; } // returning capacity of the vector
	void add(data_type temp)			// adding element in the vector
	{
		if (count == Capacity) // if the no. of element in the vector is equal to the capacity then increasing the size of the vector
		{
			increase();
		}
		ptr[type][count] = temp; // adding element
		count++;				 // increasing count(because it is the count of element in the vector)
	}
	void addAt(data_type temp, int index) // inserting element at particular index
	{
		if (count == Capacity) // if the no. of element in the vector is equal to the capacity then increasing the size of the vector
		{
			increase();
		}
		for (int i = (count - 1); i >= index; i--) // shifting the element to insert the given element
		{
			ptr[type][i + 1] = ptr[type][i];
		}
		ptr[type][index] = temp; // inserting the element
		count++;
	}
	void pop() // for deleting the last element of the vector
	{
		ptr[type][count - 1] = 0;
		count--;
	}
	void popAt(int index) // deleting the element of particular index
	{
		for (int i = index; i < count; i++)
		{
			ptr[type][i] = ptr[type][i + 1];
		}
		count--;
	}
	data_type *begin() { return &ptr[type][0]; }   // returning the address of the starting of vector
	data_type *end() { return &ptr[type][count]; } // returning the address of the ending of vector
	data_type at(int index)						   // returning the value at particular index
	{
		return ptr[type][index];
	}
	void resize(int size) // changing the size of the vector
	{
		type ? type = 0 : type = 1;
		Capacity = size;
		ptr[type] = new data_type[Capacity];
		int temp = (type) ? 0 : 1;
		int iter;
		if (count < Capacity)
		{
			iter = count;
		}
		else
		{
			iter = Capacity;
			count = Capacity;
		}
		for (int i = 0; i < iter; i++)
		{
			ptr[type][i] = ptr[temp][i];
		}
		delete[] ptr[temp];
		ptr[temp] = NULL;
	}
	void clear() // clearing the vector
	{
		delete[] ptr[type];
		ptr[type] = NULL;
		type = 0;
		count = 0;
		Capacity = 2;
		ptr[type] = new data_type[Capacity];
	}
	void assign(int size, int element) // assigning a same element for particular size
	{
		clear();
		type = 0;
		Capacity = size;
		count = size;
		ptr[type] = new data_type[Capacity];
		for (int i = 0; i < size; i++)
		{
			ptr[0][i] = element;
		}
	}
	void show() // showing the vector
	{
		if (!count)
		{
			std::cout << "[NULL]";
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				i ? std::cout << "," : std::cout << "[";
				std::cout << " " << ptr[type][i];
			}
			std::cout << " ]";
		}
	}
};