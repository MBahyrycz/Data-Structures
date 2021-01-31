#include "DataStructures.h"
#include <iostream>

/* * * *
  * comment sellected #define ... to switch off corresponding example
  * * * *
  */
//#define _ARRAY_EXAMPLE
#define _VECTOR_EXAMPLE

int main()
{
#ifdef _ARRAY_EXAMPLE 
	Array<int, 5> array;

	memset(array.Data(), 0, array.Size() * sizeof(int));
	array[1] = 7;
	array[4] = 3;

	for (size_t i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << std::endl;
	}

	int* ptr = array.Data();
	std::cout << *(ptr + 1);
#endif // _ARRAY_EXAMPLE

#ifdef _VECTOR_EXAMPLE
	Vector<float> vector;
	vector.PushBack(1.9f);
	vector.PushBack(1.72f);
	vector.PushBack(2.0f);
	vector.EmplaceBack(2.3f);
	vector.EmplaceBack(4.45f);
	vector.EmplaceBack(5.56f);
	vector.PushBack(7.0f);
	vector.PushBack(2.34f);
	vector[5] = 0.0f;
	vector[6] = 0.0f;

	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "===============================" << std::endl;

	vector.PopBack();
	vector.PopBack();

	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "===============================" << std::endl;


	vector.Clear();

	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "===============================" << std::endl;


#endif // _VECTOR_EXAMPLE

	std::cin.get();

	return 0;
}