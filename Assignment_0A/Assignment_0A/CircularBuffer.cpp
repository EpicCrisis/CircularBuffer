#include <iostream>
#include <Windows.h>
#include <array>
#include "CircularBuffer.h"

void CircularBuffer::pushBack(float _value)
{
    // Access the value of the tail index, then replace it with _value.
    arrayValue[tail] = _value;
    ++tail;
}

void CircularBuffer::pushFront(float _value)
{
    // Access the value of the head index, then replace it with _value.

}

void CircularBuffer::popFront()
{
    // Access the head index, then erase the index.
}

void CircularBuffer::popBack()
{
    // Access the tail index, then erase the index.
}

int CircularBuffer::getSize()
{
    return size;
}

float CircularBuffer::getValue(int _location)
{
    return 0.0f;
}

void CircularBuffer::getFront()
{
    // Access the head index and return the value of the index.
}

void CircularBuffer::getBack()
{
    // Access the tail index and return the value of the index.
}

int main(void)
{

}