#pragma once
#include <cmath>
#include "question_a.cpp"

bool isPrime(int n)
{
    if(n<2) return 0;
    if(n==2) return 1;
    if(!(n&1)) return 0;

    for(int i=3; i<=sqrt(n); i+=2)
        if(n%i == 0) return 0;

    return 1;
}

void printPrime(List* a)
{
    bool notFind = true;
    Node* tmp = a->pHead;

    while(tmp != NULL)
    {
        if(isPrime(tmp->n))
        {
            cout << tmp->n << " ";
            notFind = false;
        }
        tmp = tmp->pNext;
    }

    if(notFind) cout << "0";
    cout << endl;
}