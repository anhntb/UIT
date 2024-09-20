#pragma once
#include "question_a.cpp"
#include "question_b.cpp" //createNode(), pushFront(), pushBack()

void insertMidList(List* a, int index, Node* X) //0 < index < số lượng phần tử
{
    Node* tmp = a->pHead;

    while((index-1) > 0) //*tmp trả về phần tử có vị trí ngay trước vị trí cần chèn
    {
        tmp = tmp->pNext;
        index--;
    }

    X->pNext = tmp->pNext;
    tmp->pNext = X;
}

void addX_desList(List* a, int x) //descending list
{
    Node* tmp = a->pHead;
    int idx = 0;

    //insert head
    if(x >= tmp->n)
    {
        pushFront(a, createNode(x));
        goto end;
    }
    
    //insert tail
    if(x <= a->pTail->n)
    {
        pushBack(a, createNode(x));
        goto end;
    }

    //insert middle
    do //* tmp trả về vị trí phần tử có giá trị <= x
    {
        tmp = tmp->pNext;
        idx++;
    }while(x < tmp->n);
    
    insertMidList(a, idx, createNode(x));
    
    end:;
}