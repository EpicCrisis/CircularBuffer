#pragma once
#define BUFFER_SIZE 7

class CircularBuffer
{
private:

public:
    int head;
    int tail;
    int size;
    float arrayValue[BUFFER_SIZE];

    void pushBack(float _value);
    void pushFront(float _value);
    void popFront();
    void popBack();
    int getSize();
    float getValue(int _location);
    void getFront();
    void getBack();
};