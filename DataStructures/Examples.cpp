#include "DataStructures.h"
#include <iostream>

#include <array>

#define _CONTAINER_DEBUG 1

int main()
{
	Array<int, 3> array;
	array[0] = 0;
	array[1] = 7;
	array[2] = 3;

	for (size_t i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << std::endl;
	}

	int* ptr = array.Data();
	std::cout << *(ptr + 1);

	return 0;
}