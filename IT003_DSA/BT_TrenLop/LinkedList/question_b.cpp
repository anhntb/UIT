#pragma once
#include "question_a.cpp"

Node* createNode(unsigned int x)
{
    Node* tmp = new Node;
    if(tmp == NULL)
    {
        cout << "Memory overflow!" << endl;
        exit(1);
    }

    tmp->n = x;
    return tmp;
}

void pushFront(List* a, Node* b)
{
    if(a->pHead == NULL)
    {
        a->pHead = b;
        a->pTail = b;
    }
    else
    {
        b->pNext = a->pHead;
        a->pHead = b;
    }
}

void pushBack(List* a, Node* b)
{
    if(a->pHead == NULL)
    {
        a->pHead = b;
        a->pTail = b;
    }
    else
    {
        a->pTail->pNext = b;
        a->pTail = b;
    }
}

void enterList_B(List* a) // dừng khi nhập -1
{
    int x;
    cin >> x;

    while(x != -1)
    {
        pushBack(a, createNode(x));
        cin >> x;
    }
}

void enterList_F(List* a) // dừng khi nhập -1
{
    int x;
    cin >> x;
    
    while(x != -1)
    {
        pushFront(a, createNode(x));
        cin >> x;
    }
}
