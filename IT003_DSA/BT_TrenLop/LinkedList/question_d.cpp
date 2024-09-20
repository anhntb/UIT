/*
Giải bằng 2 cách:
+ Cách 1: giữ nguyên liên kết, thay đổi dữ liệu bên trong
+ Cách 2: giữ nguyên dữ liệu, thay đổi các liên kết
*/

#pragma once
#include "question_a.cpp"
#include "question_b.cpp" //pushFront()

//TODO: Cách 1----------------------------------------------------------------------------------------------
void reverseList(List* a)
{
    List* tmpL = new List;
    Node* tmpN;
    
    while(a->pHead != NULL)
    {
        tmpN = a->pHead;
        a->pHead = a->pHead->pNext;
        tmpN->pNext = NULL;
        pushFront(tmpL, tmpN);
    }

    a->pHead = tmpL->pHead;
    a->pTail = tmpL->pTail;
}

void sortList(List* a, bool asc = 1) //*ascending
{
    Node* tmp_i = a->pHead;
    while(tmp_i != a->pTail)
    {
        Node* tmp_j = tmp_i->pNext;
        while(tmp_j != NULL)
        {
            if(tmp_i->n > tmp_j->n)
                swap(tmp_i->n, tmp_j->n);
            tmp_j = tmp_j->pNext;
        }
        tmp_i = tmp_i->pNext;
    }

    if(!asc) reverseList(a);
}

//TODO: Cách 2----------------------------------------------------------------------------------------------