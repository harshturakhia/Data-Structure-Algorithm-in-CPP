#include "bits/stdc++.h"
using namespace std;

class Queue
{

    private:
        int q[20];
        int front, rear, n = 20;
    public:
        Queue()
        {
            front = rear = -1;
            n = 20;
        }
        Queue(int n)
        {
            this -> n = n;
            front = rear = -1;
        }

        bool isFull()
        {
            if(rear == n -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isEmpty()
        {
            if(front == -1 && rear == -1)
            {
                 return true;
            }
            else
            {
                return false;
            }
        }

        void Enqueue(int x)
        {
            if(isFull())
            {
                cout<<"Queue overflow...\n";
                return;
            }
            if(front == -1)
            {
                front = 0;
            }

            rear++;
            q[rear] = x;

        }
        int Dequeue()
        {
            if(isEmpty())
            {
                cout<<"Queue underflow...\n";
                return -1;
            }

            int temp = q[front];

            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }

            return temp;
        }

        int search(int key)
        {
            if(isEmpty())
            {
                cout<<"Queue underflow...\n";
                return -1;
            }

            for(int i=front; i<= rear; i++)
            {
                if(q[i] == key)
                {
                    return (i+1);
                }
            }
            cout<<"Key not found! \n";
            return -1;
        }

        void replace(int key, int newVal)
        {
            if(isEmpty())
            {
                cout<<"Queue underflow...\n";
                return;
            }

            for(int i = front; i<= rear; i++)
            {
                if(q[i] == key)
                {
                    q[i] = newVal;
                    return ;
                }
            }
            cout<<"Key not found! \n";
            return;
        }
        void traverse()
        {
            cout<<"Front : "<<front <<endl;

            for(int i=front; i<= rear; i++)
            {
                cout<<q[i]<<endl;
            }
            
            cout<<"Rear : "<<rear<<endl<<endl<<endl;
        }
};

int main()
{
    Queue q1(15);

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Enqueue(50);

    q1.traverse();

    cout<<"Deleted element is : "<<q1.Dequeue()<<endl;
    q1.traverse();

    cout<<"Deleted element is : "<<q1.Dequeue()<<endl;
    q1.traverse();

    cout<<"Deleted element is : "<<q1.Dequeue()<<endl;
    q1.traverse();

    cout<<"Deleted element is : "<<q1.Dequeue()<<endl;
    q1.traverse();

    // q1.Enqueue(60);
    // q1.Enqueue(70);
    // q1.Enqueue(80);
    // q1.Enqueue(90);
    // q1.traverse();

    // int pos = q1.search(100);
    // if(pos>0)
    // {
    //     cout<<"Key found at position : "<<pos<<endl;
    // }

    // q1.replace(60,99);
    // q1.traverse();

}