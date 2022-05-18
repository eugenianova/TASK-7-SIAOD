#pragma once
#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

struct Node //Узел
{
    Node* pNext; //указатель на следующий элемент
    int data; //значение узла

    Node(int s, Node* ptr = nullptr) //конструктор узла
    {
        data = s;
        pNext = nullptr;
    }
};

struct Queue //Очередь
{
    Node* first; //указатель на первый элемент
};

class Queue_list
{
private:
    Queue queue;
public:
    Queue_list();
    void push(int c);
    int pop();
    int front();
    bool is_empty();
    void make_empty();

};

Queue_list::Queue_list()
{
    queue.first = nullptr;
}

void Queue_list::push(int c)
{
    Node* new_node = new Node(c);
    if (queue.first == nullptr)
        queue.first = new_node;
    else
    {
        Node* curr = queue.first;
        while (curr->pNext != nullptr)
            curr = curr->pNext;
        curr->pNext = new_node;
    }
}

int Queue_list::pop()
{
    int c = queue.first->data;
    queue.first = queue.first->pNext;
    return c;
}

int Queue_list::front()
{
    return queue.first->data;
}

bool Queue_list::is_empty()
{
    return (queue.first == nullptr);
}

void Queue_list::make_empty()
{
    queue.first = nullptr;
}
