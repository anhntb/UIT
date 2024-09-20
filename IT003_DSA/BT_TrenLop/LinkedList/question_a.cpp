#pragma once
#include <iostream>

using namespace std;

struct Node
{
    unsigned int n;
    Node* pNext = NULL;
};

struct List
{
    Node* pHead = NULL;
    Node* pTail = NULL;
};