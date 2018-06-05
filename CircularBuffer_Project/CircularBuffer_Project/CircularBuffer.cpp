#include <iostream>
#include <Windows.h>
#include <array>
#include "CircularBuffer.h"

void CircularBuffer::pushBack(char _value)
{
    // Access the value of the head index, then replace it with _value.
    arrayValue[head] = _value;
    head = (head + 1) % BUFFER_SIZE;
    ++size;

    // Check for overflow.
    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload, replacing oldest index!" << std::endl;
        size -= overflow;
        tail = (tail + overflow) % BUFFER_SIZE;
    }
}

// [Not finished]
void CircularBuffer::pushFront(char _value)
{
    // Access the value of the tail index, then replace it with _value.
    arrayValue[head] = _value;
    head = (head + 1) % BUFFER_SIZE;
    ++size;

    // Check for overflow.
    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload, replacing oldest index!" << std::endl;
        size -= overflow;
        tail = (tail + overflow) % BUFFER_SIZE;
    }
}

char CircularBuffer::popFront()
{
    // Access the head index, then erase the index.
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popFront" << std::endl;
        return NULL;
    }

    char value = getFront();

    head = head - 1;
    if (head <= 0)
    {
        head += BUFFER_SIZE;
    }
    --size;
    return value;
}

char CircularBuffer::popBack()
{
    // Access the tail index, then erase the index.
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popBack." << std::endl;
        return NULL;
    }

    char value = getBack();

    tail = (tail + 1) % BUFFER_SIZE;
    --size;
    return value;
}

int CircularBuffer::getSize()
{
    return size;
}

char CircularBuffer::getValue(int _location)
{
    // Get index relative to the oldest position.
    int currentIndex = (tail + _location) % BUFFER_SIZE;
    return arrayValue[currentIndex];
}

char CircularBuffer::getLocation(int _location)
{
    // Get index directly from the true position.
    int currentIndex = _location;
    return arrayValue[currentIndex];
}

char CircularBuffer::getFront()
{
    // Access the head index and return the value of the index.
    return arrayValue[head];
}

char CircularBuffer::getBack()
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