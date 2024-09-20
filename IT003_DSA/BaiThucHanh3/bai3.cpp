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

Node* createNode(const int &n)
{
    Node* tmp = new Node;
    if(tmp == NULL)
    {
        cout << "Cap phat bo nho that bai!" << endl;
        exit(1);
    }
    tmp->data = n;
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

void outList(const List &l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* tmp = l.pHead;
    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->pNext;
    }
}

void addX(List &l, int x)
{
    //chèn đầu
    if(l.pHead->data >= x)
    {
        Node* tmp_x = createNode(x);
        tmp_x->pNext = l.pHead;
        l.pHead = tmp_x;
        return;
    }

    //chèn cuối
    if(l.pTail->data <= x)
    {
        Node* tmp_x = createNode(x);
        l.pTail->pNext = tmp_x;
        l.pTail = tmp_x;
        return;
    }

    //chèn giữa
    Node* tmp = l.pHead;
    while(tmp != l.pTail) //duyệt đến Node kề cuối
    {
        
        if(tmp->pNext->data >= x)
        {
            Node* tmp_x = createNode(x);
            tmp_x->pNext = tmp->pNext;
            tmp->pNext = tmp_x;
            return;
        }
        else
            tmp = tmp->pNext;
    }
}

int main()
{
    List l;

    int n;
    cin >> n;
    inpList(l, n);
    
    int x;
    cin >> x;
    addX(l, x);
    outList(l);

    return 0;
}