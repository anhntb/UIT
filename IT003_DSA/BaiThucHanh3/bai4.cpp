#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext = NULL;
};

struct List
{
    Node* pHead = NULL;
    Node* pTail = NULL;
};

Node* createNode(int x)
{
    Node* tmp = new Node;
    if(tmp == NULL)
    {
        cout << "Cap phat bo nho that bai!" << endl;
        exit(1);
    }
    tmp->data = x;
    return tmp;
}

void addNode(List &l, Node* a)
{
    if(l.pHead == NULL)
    {
        l.pHead = a;
        l.pTail = a;
    }
    else
    {
        l.pTail->pNext = a;
        l.pTail = a;
    }
}

void inpList(List &l, int n)
{
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        addNode(l, createNode(x));
    }
}

void outList(List &l)
{
    Node* tmp = l.pHead;
    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->pNext;
    }
}

void reverseList(List &l)
{
    Node* i = l.pHead;
    while(i != l.pTail)
    {
        Node* j = i->pNext;
        while(j != NULL)
        {
            int tmp = i->data;
            i->data = j->data;
            j->data = tmp;
            j = j->pNext;
        }
        i = i->pNext;
    }
}

int main()
{
    List l;

    int n;
    cin >> n;
    inpList(l, n);

    reverseList(l);
    outList(l);

    return 0;
}