#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class Queue_arr //реализация на массиве
{
private:
    vector<int> queue;
public:
    void push(int c);
    int pop();
    int front();
    bool is_empty();
    void make_empty();

};

void Queue_arr::push(int c)
{
    queue.push_back(c);
}

int Queue_arr::pop()
{
    int c = queue[0];
    queue.erase(queue.begin());
    return c;
}

int Queue_arr::front()
{
    return queue[0];
}

bool Queue_arr::is_empty()
{
    return queue.empty();
}

void Queue_arr::make_empty()
{
    queue.clear();
}
