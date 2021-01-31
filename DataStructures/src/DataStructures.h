#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/* * * * 
 *  One header file library with simple implementation of
 *  basic STL data structures. Easy to use, easy to modify,
 *  easy to add new features.
 * * * *
 */

#include <memory>

 /* * * *
  * change value of _CONTAINER_DEBUG to 0 to switch off debug mode
  * * * *
  */
#define _CONTAINER_DEBUG 1
  

 /* * * *
  *  Array class container - simple stack alocated array, that
  *  stores data continuously.
  *  Can be specified as array of each type.
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
#if _CONTAINER_DEBUG > 0
        if (!(index < S))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    const T& operator[](size_t index) const
    {
#if _CONTAINER_DEBUG > 0
        if (!(index < S))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    //TODO: iterators, empty(), fill()
private:
    T m_Data[S];
};

/* * * *
 *  Vector class container - simple dynamically alocated container, that
 *  stores data continuously. All data is stored on heap.
 *  Can be specified as array of each type.
 *
 * * * *
 */

template<typename T>
class Vector
{
public:
    Vector()
    {
        // alocate size for 2 elements at the start, can be changed if needed
        ReAlloc(2);
    }

    ~Vector()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);   // growing vector size by 50%, can be changed if needed

        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);   // growing vector size by 50%, can be changed if needed

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);   // growing vector size by 50%, can be changed if needed

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
  
        return m_Data[m_Size++];
    }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    T& operator[](size_t index)
    {
#if _CONTAINER_DEBUG > 0
        if (!(index < m_Size))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    const T& operator[](size_t index) const
    {
#if _CONTAINER_DEBUG > 0
        if (!(index < m_Size))
            __debugbreak(); // INDEX OUT OF RANGE
#endif // _CONTAINER_DEBUG
        return m_Data[index];
    }

    constexpr size_t Size() const { return m_Size; }
private:
    void ReAlloc(size_t newCapacity)
    {
        // 1. allocate a new block of memory
        // 2. moving stored elements to new block
        // 3. freeing memory


        /* BUG WITH ALLOCATING MEMORY WITHOUT CONTRUCTORS IN STD::STRING */
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
        //T* newBlock = (T*)malloc(newCapacity * sizeof(T));
        //T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;                   // for realocating smaller vector than before

        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);     // memcpy can cause some problems with higher lvl structures as classes
        
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        //delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;
};


#endif