#pragma once
#define BUFFER_SIZE 5

class CircularBuffer
{
private:
    int head;
    int tail;
    int size;
    float arrayValue[BUFFER_SIZE];

public:
    void pushBack(float _value);
    void pushFront(float _value);
    float popFront();
    float popBack();
    int getSize();
    float getValue(int _location);
    float getFront();
    float getBack();
    CircularBuffer();
};