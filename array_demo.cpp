#include <iostream>
using namespace std;

class Array
{
    int a[20];
    int n;

public:
    Array()
    {
        n = 0;
    }
    Array(int n)
    {
        this->n = n;
    }
    void setArray()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter elements : ";
            cin >> a[i];
        }
    }
    void traverse()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i]
                 << " \t "
                 << endl;
        }
        cout << endl;
    }
    int insert(int pos, int newVal)
    {
        for (int i = n - 1; i >= pos - 1; i--)
        {
            a[i + 1] = a[i];
        }
        a[pos - 1] = newVal;
        n++;
        cout << endl;
    }

    int del(int pos)
    {
        int temp = a[pos - 1];
        for (int i = pos - 1; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = 0;
        n--;
        return (temp);
    }

    void reverse()
    {
        int i, j, temp;
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        cout << endl;
    }

    void shiftLeft()
    {
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = 0;
        cout << endl;
    }

    void shiftRight()
    {
        for (int i = n - 2; i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
        a[0] = 0;
        cout << endl;
    }

    void rotateLeft()
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
        cout << endl;
    }

    void rotateRight()
    {
        int temp;
        for (int i = n - 2; i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
        a[0] = temp;
        cout << endl;
    }
};

int main()
{
    int n;

    cout << "Enter how many elements you want to put : ";
    cin >> n;

    Array x(n);
    x.setArray();

    cout << "You given elements of Array : ";
    x.traverse();

    int choice;
    while (choice != 8)
    {
        system("cls");

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. ShiftRight" << endl;
        cout << "4. ShiftLeft" << endl;
        cout << "5. RotateRight" << endl;
        cout << "6. RotatLeft" << endl;
        cout << "7. Reverse" << endl;
        cout << "8. Exit" << endl;
        cout << "---------------------";
        cout << endl
             << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int p, nv;
            cout << "Enter position where you want to insert : ";
            cin >> p;
            cout << "Enter the value : ";
            cin >> nv;
            x.insert(p, nv);
            x.traverse();
            cout << endl;
            break;

        case 2:
            int pos;
            cout << "Enter position where you want to delete : ";
            cin >> pos;
            x.del();
            x.traverse();
            cout << endl;
            break;

        case 3:
            cout << "Shifting right...\n";
            x.shiftRight();
            x.traverse();
            cout << endl;
            break;

        case 4:
            cout << "Shifting left...\n";
            x.shiftLeft();
            x.traverse();
            cout << endl;
            break;

        case 5:
            cout << "Rotating right...\n";
            x.rotateRight();
            x.traverse();
            cout << endl;
            break;

        case 6:
            cout << "Rotating left...\n";
            x.rotateLeft();
            x.traverse();
            cout << endl;
            break;

        case 7:
            cout << "Reversing your elements...\n";
            x.reverse();
            x.traverse();
            cout << endl;

        case 8:
            cout << "Exited!\n";
            break;
        }
    }
}
