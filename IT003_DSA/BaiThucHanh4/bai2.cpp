#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode* pLeft = NULL;
    TNode* pRight = NULL;
};

typedef TNode* Tree;

Tree createTree()
{
    return NULL;
}

TNode* createTNode(int data)
{
    TNode* tmp = new TNode;
    if(!tmp) //tmp == NULL
    {
        cout << "Cap phat that bai!" << endl;
        exit(1);
    }
    tmp->data = data;
    return tmp;
}

void insertTNode(Tree &T, int data) 
{
    if(T == NULL)
    {
        T = createTNode(data); 
        return;
    }

    if(data < T->data)
        insertTNode(T->pLeft, data);

    if(data > T->data)
        insertTNode(T->pRight, data);
}

int heightTree(const Tree &T)
{
    if(!T) //T == NULL
        return -1;

    int left = heightTree(T->pLeft);
    int right = heightTree(T->pRight);

    return (left > right ? left : right) + 1;
}

int main()
{
    int n;
    cin >> n;

    int x;
    Tree T = createTree();

    for(int i=0; i<n; i++)
    {
        cin >> x;
        insertTNode(T, x);
    }

    cout << heightTree(T);
    
    return 0;
}