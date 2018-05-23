#include <iostream>
#include "CircularBuffer.h"

using namespace std;

int main(void)
{
    CircularBuffer cb;

    while (true)
    {
        float input;
        cin >> input;
        cb.pushFront(input);

        for (int i = 0; i < cb.getSize(); ++i)
        {
            cout << cb.getValue(i) << " ";
        }
        cout << endl;
    }

    system("PAUSE");
    return 0;
}