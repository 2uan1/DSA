#include <iostream>

using namespace std;

void pairCounter(int a[], int size)
{
    int pairs = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                pairs++;
            }
        }
    }
    cout << pairs << endl;
}

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList{
public:
    Node* head;

    void insert(int position, int data)//doesnt work for position 0 yet
    {
        if (head == nullptr)
        {
            head = new Node(data);
            head->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            Node* cur = head;
            for (int i = 0; i < position-1; i++)
            {
                if (cur == nullptr) break;
                cur = cur->next;
            }
            Node* newNode = new Node(data);
            newNode->next = cur->next;
            newNode->prev = cur;

            cur->next = newNode;

            if (cur->next->next != nullptr)
            {
                cur->next->next->prev = newNode;
            }
        }
    }

    void Delete(int position)
    {
        Node* cur = head;
        for (int i = 0; i < position-1; i++)
        {
            if (cur == nullptr) break;
            cur = cur->next;
        }
        if (cur->next->next != nullptr)
        {
            cur->next = cur->next->next;
        }
        else
        {
            delete cur->next;
            cur->next = nullptr;
        }
    }

    void printList()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
    }

    void readCommand()
    {
        int commandCount;
        cin >> commandCount;
        for (int i = 0; i < commandCount; i++)
        {
            string command;
            cin >> command;
            if (command == "insert")
            {
                int position, number;
                cin >> position >> number;
    //            cout << "inserting..." << endl;
                this->insert(position, number);
            }
            else if (command == "delete")
            {
                int position;
                cin >> position;
    //            cout << "deleting..." << endl;
                this->Delete(position);
            }
        }
    }

    void readList(int array[], int size)
    {
        this->insert(0, array[0]);
        for (int i = 1; i < size; i++)
        {
            this->insert(i, array[i]);
        }
    }

    void count_triplets()
    {
        int count = 0;
        Node* cur = head;
        cur = cur->next;
        while(cur->next != nullptr)
        {
            if (cur->data + cur->prev->data + cur->next->data == 0)
            {
                count++;
            }
            cur = cur->next;
        }
        cout << "triplet count: " << count;
    }
};

class Queue{
public:
    Node* head;
    Node* tail;

    void enqueue(int x)
    {
        if (head == nullptr)
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            Node* newNode = new Node(x);
            newNode->next = nullptr;
            newNode->prev = tail;

            tail->next = newNode;

            tail = tail->next;
        }
    }

    void dequeue()
    {
        head = head->next;
    }

    void printQueue()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
    }

    void readCommand()
    {
        int commandCount;
        cin >> commandCount;
        for (int i = 0; i < commandCount; i++)
        {
            string command;
            cin >> command;
            if (command == "enqueue")
            {
                int number;
                cin >> number;
                this->enqueue(number);
            }
            else if (command == "dequeue")
            {
                this->dequeue();
            }
        }
    }
};

class Stack{
public:
    Node* head;
    Node* top;

    void push(int x)
    {
        if (top == nullptr)
        {
            top = new Node(x);
            top->next = nullptr;
            top->prev = nullptr;
            head = top;
        }
        else
        {
            Node* newNode = new Node(x);
            newNode->next = nullptr;
            newNode->prev = top;

            top->next = newNode;

            top = top->next;
        }
    }

    void pop()
    {
        top = top->prev;
    }

    void print()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
    }

    void readCommand()
    {
        int commandCount;
        cin >> commandCount;
        for (int i = 0; i < commandCount; i++)
        {
            string command;
            cin >> command;
            if (command == "push")
            {
                int number;
                cin >> number;
                this->push(number);
            }
            else if (command == "pop")
            {
                this->pop();
            }
        }
    }
};