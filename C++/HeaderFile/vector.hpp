#ifndef iostream
#include <iostream>
#endif
template <class data_type>
class vector
{
private:
	int Capacity = 0, count = 0;
	int type = 0;
	data_type *ptr[2];
	void increase()
	{
		type ? type = 0 : type = 1;
		(!Capacity) ? Capacity = 1 : Capacity *= 2;
		ptr[type] = new data_type[Capacity];
		int temp = (type) ? 0 : 1;
		for (int i = 0; i < Capacity / 2; i++)
		{
			ptr[type][i] = ptr[temp][i];
		}
		delete[] ptr[temp];
		ptr[temp] = NULL;
	}

public:
	vector()
	{
		ptr[0] = NULL;
		ptr[1] = NULL;
	}
	vector(int size)
	{
		Capacity = size;
		ptr[0] = new data_type[Capacity];
		ptr[1] = NULL;
	}
	int size() { return count; }
	int capacity() { return Capacity; }
	void add(data_type temp)
	{
		if (count == Capacity)
		{
			increase();
		}
		ptr[type][count] = temp;
		count++;
	}
	void addAt(data_type temp, int index)
	{
		if (count == Capacity)
		{
			increase();
		}
		for (int i = (count - 1); i >= index; i--)
		{
			ptr[type][i + 1] = ptr[type][i];
		}
		ptr[type][index] = temp;
		count++;
	}
	void pop()
	{
		ptr[type][count - 1] = 0;
		count--;
	}
	void popAt(int index)
	{
		for (int i = index; i < count; i++)
		{
			ptr[type][i] = ptr[type][i + 1];
		}
		count--;
	}
	data_type *begin() { return &ptr[type][0]; }
	data_type *end() { return &ptr[type][count]; }
	data_type at(int index)
	{
		return ptr[type][index];
	}
	void resize(int size)
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
	void clear()
	{
		delete[] ptr[type];
		ptr[type] = NULL;
		type = 0;
		count = 0;
		Capacity = 2;
		ptr[type] = new data_type[Capacity];
	}
	void assign(int size, int element)
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
	void show()
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