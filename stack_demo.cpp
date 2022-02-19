#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class Stack
{
    int s[20];
    int n, Top;

public:
    Stack()
    {
        n = 20;
        Top = -1;
    }
    Stack(int n)
    {
        this->n = n;
        Top = -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow...";
            return;
        }
        Top++;
        s[Top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow...";
            return (0);
        }

        int Temp = s[Top];
        Top--;
        return (Temp);
    }
    int peep(int i)
    {
        if (Top - i + 1 <= -1)
        {
            cout << "Stack underflow at peep..." << endl;
            return (0);
        }
        return (s[Top - i + 1]);
    }
    void change(int i, int x)
    {
        if (Top - i + 1 <= -1)
        {
            cout << "Stack underflow at change..." << endl;
            return;
        }
        s[Top - i + 1] = x;
    }
    void display()
    {
        for (int i = Top; i >= 0; i--)
        {
            cout << s[i];
            if (i == Top)
            {
                cout << "Top";
            }
            else
            {
                cout << endl;
            }
        }
    }

    bool isFull()
    {
        if (Top == n - 1)
        {
            return true;
        }
        else
            return false;
    }
    bool isEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s1(5);
    int choice;

    while (choice != 6)
    {
        system("cls");

        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peep" << endl;
        cout << "4.Change" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;

        cout << endl
             << "--------------" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x;
            cout << "Enter new value : ";
            cin >> x;
            s1.push(x);
            break;
        }
        case 2:
        {
            cout << "The popped value is : "
                 << s1.pop() << endl;
            break;
        }
        case 3:
        {
            int i;
            cout << "Enter value of i to change : ";
            cin >> i;
            cout << "The peeped value is : "
                 << s1.peep(i) << endl;

            break;
        }

        case 4:
        {
            int i, x;
            cout << "Enter value of i for change : ";
            cin >> i;
            cout << "Enter new value : ";
            cin >> x;

            s1.change(i, x);
            break;
        }
        case 5:
        {
            s1.display();
        }
        }
    }
    getch();
}