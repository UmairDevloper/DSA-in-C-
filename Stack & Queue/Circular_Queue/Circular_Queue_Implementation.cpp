// # Circular Queue Implementation (Array & Linked List)

// ```cpp
/*
Problem Statement:
Implement a Circular Queue with the following operations:
- enqueue(x): Insert an element into the circular queue.
- dequeue(): Delete an element from the circular queue.
- Front(): Get the front element.
- Rear(): Get the last element.
- isEmpty(): Check if the queue is empty.
- isFull(): Check if the queue is full.

Approach 1: Array-based Circular Queue
- Maintain an array of fixed size `cap`.
- Use two pointers: `front` and `rear`.
- Use modular arithmetic (index % cap) to wrap around.
- Track the size of the queue to handle empty/full cases.

Approach 2: Linked List-based Circular Queue
- Use a circular singly linked list where the last node points to the front node.
- Maintain `front` and `rear` pointers.
- Enqueue inserts at the rear, Dequeue removes from the front.
- Space is dynamic (limited only by memory).

Time Complexity (Both Approaches):
- Enqueue: O(1)
- Dequeue: O(1)
- Front/Rear: O(1)

Space Complexity:
- Array: O(cap)
- Linked List: O(n), where n is number of elements in queue.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////
// Approach 1: Circular Queue using Array
//////////////////////////////////////
class CircularQueueArray
{
    int *arr;
    int front, rear, size, cap;

public:
    CircularQueueArray(int capacity)
    {
        cap = capacity;
        arr = new int[cap];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull()
    {
        return size == cap;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        front = (front + 1) % cap;
        size--;
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }
};

//////////////////////////////////////
// Approach 2: Circular Queue using Linked List
//////////////////////////////////////
class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class CircularQueueLinkedList
{
    Node *front;
    Node *rear;

public:
    CircularQueueLinkedList()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (isEmpty())
        {
            front = rear = temp;
            rear->next = front;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }

    int Rear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return rear->data;
    }
};

//////////////////////////////////////
// Driver Code
//////////////////////////////////////
int main()
{
    cout << "=== Circular Queue using Array ===\n";
    CircularQueueArray cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Front: " << cq.Front() << endl; // 10
    cout << "Rear: " << cq.Rear() << endl;   // 30
    cq.dequeue();
    cout << "Front after dequeue: " << cq.Front() << endl; // 20

    cout << "\n=== Circular Queue using Linked List ===\n";
    CircularQueueLinkedList cql;
    cql.enqueue(1);
    cql.enqueue(2);
    cql.enqueue(3);
    cout << "Front: " << cql.Front() << endl; // 1
    cout << "Rear: " << cql.Rear() << endl;   // 3
    cql.dequeue();
    cout << "Front after dequeue: " << cql.Front() << endl; // 2

    return 0;
}
