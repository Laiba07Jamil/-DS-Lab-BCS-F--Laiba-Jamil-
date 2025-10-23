#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{
public:
    char *arr;
    int capacity;
    int top;

    Stack(int cap = 0)
    {
        capacity = cap;
        top = -1;
        arr = new char[capacity];
    }

    ~Stack()
    {
        delete[] arr;
        arr = nullptr;
    }

    void push(char n)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = n;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top < 0)
            return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class queue
{
public:
    int *arr;      // stores process IDs
    int *priority; // stores corresponding priorities
    int capacity;
    int size;

    queue(int cap = 0)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        priority = new int[capacity]; // priority array created
    }

    void enqueue(int id, int p)
    {
        if (isfull())
        {
            cout << "Queue overflow\n";
            return;
        }
        arr[size] = id;
        priority[size] = p;
        size++;
    }
    ~queue()
    {
        delete[] arr;
        arr = nullptr;
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int data = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return data;
    }

    void display()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isempty() { return size == 0; }
    bool isfull() { return size == capacity; }
};
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    queue jobQueue(n);
    Stack executionStack(n);

    // input for processes
    for (int i = 0; i < n; i++)
    {
        int id, priority;
        cout << "\nEnter process ID: ";
        cin >> id;
        cout << "Enter priority (1 low, 2 medium, 3 high): ";
        cin >> priority;

        jobQueue.enqueue(id, priority);
    }

    cout << "\nProcesses in queue:\n";
    for (int i = 0; i < jobQueue.size; i++)
    {
        cout << "Process ID: " << jobQueue.arr[i]
             << " | Priority: " << jobQueue.priority[i] << endl;
    }

    // move high priority to stack
    cout << "\nMoving high priority jobs to stack...\n";
    for (int i = 0; i < jobQueue.size; i++)
    {
        if (jobQueue.priority[i] == 3)
        {
            executionStack.push(jobQueue.arr[i]);
            cout << "Pushed process " << jobQueue.arr[i] << " to stack\n";
        }
    }

    cout << "\nExecuting high priority jobs from stack:\n";
    while (!executionStack.isEmpty())
    {
        int process = executionStack.pop();
        cout << "Running process " << process << " (high priority)\n";
    }

    cout << "\nExecuting remaining jobs from queue:\n";
    for (int i = 0; i < jobQueue.size; i++)
    {
        if (jobQueue.priority[i] != 3)
        {
            cout << "Running process " << jobQueue.arr[i]
                 << " (priority " << jobQueue.priority[i] << ")\n";
        }
    }

    return 0;
}