#include <iostream>
using namespace std;

class Queue
{
    int front, rear, size;
    int *Q;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue ::enqueue(int x)
{
    if (rear = size - 1)
    {
        cout << "Queue overflow..." << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue ::dequeue()
{
    if (front > rear || front == -1)
    {
        cout << "Queue underflow..." << endl;
    }
    else
    {
        front++;
    }
}

void Queue ::display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << Q[i] << endl;
    }
}

int main()
{
    Queue q(6);

    q.enqueue(5);
    q.enqueue(10);

    q.display();

    q.enqueue(15);
    q.enqueue(20);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
}