#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int queue_[N];
int n;
int front = -1, rear = -1;

void enqueue_() {
    if ((rear + 1) % n == front) {
        cout << "Overflow!" << endl;
        return;
    }
    int x;
    cout << "Number you want to enqueue: ";
    cin >> x;
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue_[rear] = x;
}

void deque_() {
    if (front == -1 && rear == -1) {
        cout << "Underflow!" << endl;
        return;
    }
    cout << "Removed number: " << queue_[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }
    int i = front;
    while (true) {
        cout << queue_[i] << ' ';
        if (i == rear) break;
        i = (i + 1) % n;
    }
    cout << endl;
}

int main() {
    cout << "Size of circular queue: ";
    cin >> n;
    cout << "How many functions you want to do: ";
    int times;
    cin >> times;
    while (times--) {
        cout << "Type the following function you want to use :\n1.enqueue\n2.dequeue\n3.peek\n4.display\n";
        string s;
        cin >> s;
        if (s == "enqueue")
            enqueue_();
        else if (s == "dequeue")
            deque_();
        else if (s == "peek") {
            if (front == -1 && rear == -1)
                cout << "Queue is Empty" << endl;
            else
                cout << queue_[front] << endl;
        }
        else if (s == "display")
            display();
    }
    return 0;
}
