#include <iostream>
#include <Windows.h>
#include <array>
#include "CircularBuffer.h"

void CircularBuffer::pushBack(float _value)
{
    // Access the value of the head index, then replace it with _value.
    arrayValue[head] = _value;
    head = (head + 1) % BUFFER_SIZE;
    ++size;

    // Check for overflow.
    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload!" << std::endl;
        size -= overflow;
        tail = (tail + overflow) % BUFFER_SIZE;
    }
}

void CircularBuffer::pushFront(float _value)
{
    // Access the value of the tail index, then replace it with _value.
    arrayValue[head] = _value;
    head = (head + 1) % BUFFER_SIZE;
    ++size;

    // Check for overflow.
    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload!" << std::endl;
        size -= overflow;
        tail = (tail + overflow) % BUFFER_SIZE;
    }
}

float CircularBuffer::popFront()
{
    // Access the head index, then erase the index.
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popFront" << std::endl;
        return NULL;
    }

    float value = getFront();

    head = head - 1;
    if (head <= 0)
    {
        head += BUFFER_SIZE;
    }
    --size;
    return value;
}

float CircularBuffer::popBack()
{
    // Access the tail index, then erase the index.
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popBack." << std::endl;
        return NULL;
    }

    float value = getBack();

    tail = (tail + 1) % BUFFER_SIZE;
    --size;
    return value;
}

int CircularBuffer::getSize()
{
    return size;
}

float CircularBuffer::getValue(int _location)
{
    int currentIndex = (tail + _location) % BUFFER_SIZE;

    return arrayValue[currentIndex];
}

float CircularBuffer::getFront()
{
    // Access the head index and return the value of the index.
    return arrayValue[head];
}

float CircularBuffer::getBack()
{
    // Access the tail index and return the value of the index.
    return arrayValue[tail];
}

CircularBuffer::CircularBuffer()
{   
    head = 0;
    tail = 0;
    size = 0;
}