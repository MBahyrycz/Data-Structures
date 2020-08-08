#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/* * * * 
 *  One header file library with simple implementation of
 *  basic STL data structures. Easy to use, easy to modify,
 *  easy to add new functionalities.
 * * * *
 */

#include <memory>

 /* * * *
  * define "_CONTAINER_DEBUG" to 0 to switch off debug mode
  * * * *
  */
#define _CONTAINER_DEBUG 1
  

 /* * * *
  *  Array class container - simple stack alocated array.
  *  Can bespecified as array of each type.
  *  
  * * * *
  */

template <typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() { return S; }

    T* Data() { return m_Data; }

    const T* Data() const { return m_Data; }

    T& operator[](size_t index)
    {

#ifdef _CONTAINER_DEBUG > 0
        if (!(index < S))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    const T& operator[](size_t index) const
    {
#ifdef _CONTAINER_DEBUG > 0
        if (!(index < S))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    //TODO: iterators
private:
    T m_Data[S];
};



#endif