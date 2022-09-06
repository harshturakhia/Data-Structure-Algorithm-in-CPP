#include <iostream>
#include <bits/stdc++.h>
#define n 100
using namespace std;
void Stack();
void Queue();
void Stack2(); // stack using two queues
void Queue2(); // queue using two stacks
int main()
{
    int ch;
    do
    {
        cout << "1) Stack\n2) Queue\n3) Stack using two queues\n4) Queue using two stacks\n";
        cout << "Please enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Stack();
            break;
        case 2:
            Queue();
            break;
        case 3:
            Stack2();
            break;
        case 4:
            Queue2();
            break;
        default:
            cout << "Please enter the correct choice\n";
            break;
        }
    } while (ch < 5);
    return 0;
}

void Stack()
{
    int ch;
    int i;
    int s[n];
    int top = -1;
    do
    {
        cout << "1) Push\n2) Pop\n3) Display\n";
        cout << "Please Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (top == n - 1)
            {
                cout << "Stack overflow";
                break;
            }
            cout << "Please enter item to push into stack : ";
            cin >> i;
            top++;
            s[top] = i;
            break;
        case 2:
            if (top == -1)
            {
                cout << "Stack underflow";
                break;
            }
            cout << s[top] << " popped\n";
            top--;
            break;
        case 3:
            cout << "Elements in stack : ";
            for (int j = top; j > -1; j--)
            {
                cout << s[j] << "\t";
            }
            cout << "\n";
            break;
        default:
            cout << "Please enter the correct choice\n";
            break;
        }
    } while (ch < 4);
}

void Queue()
{
    int f = -1;
    int r = -1;
    int ch;
    int i;
    int s[n];
    do
    {
        cout << "1) Insert\n2) Delete\n3) Display\n";
        cout << "Please Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (r == n - 1)
            {
                cout << "Queue is full";
                break;
            }
            if (f == -1)
            {
                f++;
            }
            cout << "Please enter item to insert into queue : ";
            cin >> i;
            r++;
            s[r] = i;
            break;
        case 2:
            if (f == r)
            {
                f == -1;
                r == -1;
                cout << "Queue is empty";
                break;
            }
            cout << s[f] << " deleted\n";
            f++;
            break;
        case 3:
            cout << "Elements in queue : ";
            for (int j = f; j <= r; j++)
            {
                cout << s[j] << "\t";
            }
            cout << "\n";
            break;
        default:
            cout << "Please enter the correct choice\n";
            break;
        }
    } while (ch < 4);
}

class Stack1
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack1()
    {
        N = 0;
    }
    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
    }
};

void Stack2()
{
    Stack1 st;
    int ch, m;
    do
    {
        cout << "1) Push\n2) Pop\n3) Location of Top\n";
        cout << "Please Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number to push : ";
            cin >> m;
            st.push(m);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            cout << st.top() << endl;
            break;
        default:
            cout << "Please enter the correct choice\n";
            break;
        }
    } while (ch < 4);
}

class Queue1
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
};

void Queue2()
{
    Queue1 q;
    int ch, m;
    do
    {
        cout << "1) Insert\n2) Delete\n";
        cout << "Please Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number to insert : ";
            cin >> m;
            q.push(m);
            break;
        case 2:
            cout << q.pop() << " deleted\n";
            break;
        default:
            cout << "Please enter the correct choice\n";
            break;
        }
    } while (ch < 3);
}