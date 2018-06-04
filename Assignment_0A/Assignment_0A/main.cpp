#include <iostream>
#include <limits>
#include "CircularBuffer.h"

using namespace std;

CircularBuffer cb;

void SetMessage()
{
    for (int i = 0; i < cb.getSize(); ++i)
    {
        cout << cb.getValue(i) << "|";
    }
    cout << endl << endl;

    cout << "Pick your poison: " << endl;
    cout << "[1] Push back a char" << endl;
    cout << "[2] Pop back a char" << endl;
    cout << "[3] Pop front a char" << endl;
    // [Not finished]
    cout << "[4] Get char from location" << endl;
}

void ResetInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(void)
{
    while (true)
    {
        char choice = NULL;
        char input = NULL;
        char selected = NULL;
        int index = NULL;
        //cin >> input;
        //cb.pushFront(input);

        SetMessage();

        while (!(cin >> choice))
        {
            ResetInput();
            cout << "Input only accepts integers: ";
        }
        ResetInput();

        switch (choice)
        {
        case '1':
            cout << "Type a char to continue: ";
            while (!(cin >> input))
            {
                ResetInput();
                cout << "Input only accepts char: ";
            }
            cb.pushBack(input);
            break;
        case '2':
            cout << "Attempting to pop back." << endl;
            cb.popBack();
            break;
        case '3':
            cout << "Attempting to pop front." << endl;
            cb.popFront();
            break;
        case '4':
            if (cb.getSize() <= 0)
            {
                cout << "Buffer is empty, no value is acquired!" << endl;
                break;
            }
            else
            {
                cout << "Select index between " << 0 << " to " << cb.getSize() - 1 << ": ";
            }

            while (!(cin >> index))
            {
                ResetInput();
                cout << "Input only accepts int: ";
            }

            selected = cb.getValue(index);
            if (index < 0 || index > cb.getSize() - 1)
            {
                cout << "Index out of range, no value is acquired!" << endl;
            }
            else
            {
                cout << "You have selected char '" << selected << "' from index " << index << "." << endl;
            }
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }

        ResetInput();
        system("PAUSE");
        system("CLS");
    }

    system("PAUSE");
    return 0;
}