#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int queue_[N];
int n;
int front = -1;
int rear = -1;
void enqueue_()
{
    if (rear == n - 1)
    {
        cout << "Overflow!" << endl;
        return;
    }
    int x;
    cout << "Number you want to enqueue: ";
    cin >> x;
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
        rear++;
    queue_[rear] = x;
}
void deque_()
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow!" << endl;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "Removed number: " << queue_[front] << endl;
        front++;
    }
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << queue_[i] << ' ';
    }
    cout << endl;
}
int main()
{
    cout << "Size of queue: ";
    cin >> n;
    cout << "How many functions you want to do: ";
    int times;
    cin >> times;
    while (times--)
    {
        cout << "Type the following function you want to use : \n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.isfull\n6.isempty";
        string s;
        cin >> s;
        if (s == "enqueue")
            enqueue_();
        else if (s == "dequeue")
            deque_();
        else if (s == "display")
            display();
        else if (s == "peek")
            cout << queue_[front] << endl;
        else if (s == "isfull")
            cout << (rear == n - 1 ? "Queue is Full" : "Queue is Not Full") << endl;
        else if (s == "isempty")
            cout << ((front == -1 && rear == -1) ? "Queue is Empty" : "Queue is Not Empty") << endl;
    }
    return 0;
}