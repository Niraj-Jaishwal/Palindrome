#include "PalindromeI.hpp"
#include <cctype>
#include <iostream>

class Node
{
public:
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr){}
};

class stackLinkedList
{
private:
    Node* top;
public:
    stackLinkedList();
    ~stackLinkedList();

    void push(char val);
    char pop();
    bool isEmpty();
};

stackLinkedList::stackLinkedList():top(nullptr){}

stackLinkedList::~stackLinkedList()
{
    while(!isEmpty())
    {
        pop();
    }
}

void stackLinkedList::push(char val)
{
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

char stackLinkedList::pop()
{
    if(isEmpty())
    {
        return 0;
    }

    char item = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return item;
}

bool stackLinkedList::isEmpty()
{
    return top == nullptr;
}

class ArrayQueue
{
private:
    static const int MAX_SIZE = 100;
    char arr[MAX_SIZE];
    int fron;
    int rear;
public:
    ArrayQueue();
    ~ArrayQueue();

    void enqueue(char val);
    char dequeue();
    bool isEmpty();
};

ArrayQueue::ArrayQueue():fron(0),rear(-1){};
ArrayQueue::~ArrayQueue()
{
};

void ArrayQueue::enqueue(char val)
{
    arr[++rear]=val;
}
char ArrayQueue::dequeue()
{
    if(isEmpty())
    {
        throw std::runtime_error("The queue is empty.\n");
    }
    char item = arr[fron++];
    return item;
}

bool ArrayQueue::isEmpty()
{
    return fron > rear || rear == -1;
}

int PalindromeI::test_string(const std::string& s)
{
    stackLinkedList stacks;
    ArrayQueue queues;
    for(char c : s)
    {
        if(isalnum(c))
        {
            stacks.push(c);
            queues.enqueue(c);
        }
    }

    //check if the characters from the stack and queue are equal
    int matches = 0;
    while(!stacks.isEmpty() && !queues.isEmpty())
    {
        char stackTop = stacks.pop();
        char queuesFront = queues.dequeue();

        if(std::tolower(stackTop) != std::tolower(queuesFront))
        {
            //not a palindrome
            return matches;
        }
        matches++;
    }
    //if both stack and queue are empty, it is a palindrome
    return -1;
}

