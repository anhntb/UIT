#include <iostream>

using namespace std;

//? Cau a: Tao cay tim kiem nhi phan
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

TNode* createTNode(int n)
{
    Tree tmp = new TNode;
    if(tmp == NULL)
    {
        cout << "Cap phat that bai!" << endl;
        exit(1);
    }
    tmp->data = n;
    return tmp;
}


//? Cau b: Them 1 phan tu moi vao cay tim kiem nhi phan
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


//? Cau c: Xoa 1 phan tu tren cay nhi phan tim kiem
void subTree(Tree &tmp, Tree &T)	
{	
    if	(T->pLeft != NULL)	
        subTree(tmp, T->pLeft);	
    else	
    {	
        tmp->data = T->data;	
        tmp = T;	
        T =	T->pRight;	
    }	
}

void eraseTNode(Tree &T, int data)
{
    if(T != NULL)	
    {	
        if(T->data < data)	
            eraseTNode(T->pRight, data);	
        else	
        {	
            if(T->data > data)	
                eraseTNode(T->pLeft, data);	
            else	
            {	
                TNode* tmp;	
                tmp =	T;	
                if(T->pLeft	== NULL)	
                    T = T->pRight;	
                else	
                {	
                    if	(T->pRight == NULL)
                        T = T->pLeft;	
                    else 
                        subTree(tmp, T->pRight);	
                }	
                delete	tmp;	
            }	
        }	
    }
}


//? Cau d: Tim kiem 1 phan tu tren cay nhi phan tim kiem
TNode* findTNode(const Tree &T, int data)
{
    Tree tmp = T;
    while(tmp) //tmp != NULL
    {
        if(data == tmp->data)
            return tmp;

        if(data < tmp->data)
            tmp = tmp->pLeft;
        else 
            tmp = tmp->pRight;
    }

    return NULL;
}


//? Cau e: Duyet cay nhi phan tim kiem
//todo: NLR
void preorder(const Tree &T)
{
    if(T != NULL)
    {
        cout << T->data << " ";
        preorder(T->pLeft);
        preorder(T->pRight);
    }
}
//todo: LNR
void inorder(const Tree &T)
{
    if(T != NULL)
    {
        inorder(T->pLeft);
        cout << T->data << " ";
        inorder(T->pRight);
    }
}
//todo: LRN
void postorder(const Tree &T)
{
    if(T != NULL)
    {
        postorder(T->pLeft);
        postorder(T->pRight);
        cout << T->data << " ";
    }
}

int main()
{
//Cau b: Them 1 phan tu vao cay nhi phan tim kiem
    cout << "---------------Cau b---------------" << endl;
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int x;
    Tree T = createTree(); //T == NULL

    cout << "Nhap lan luot cac phan tu: ";
    for(int i=0; i<n; i++)
    {
        cin >> x;
        insertTNode(T, x);
    }

//Cau c: Xoa 1 phan tu tren cay nhi phan tim kiem
    cout << "---------------Cau c---------------" << endl;
    int key;
    cout << "Nhap phan tu muon xoa: ";
    cin >> key;
    eraseTNode(T, key);

// //Cau d: Tim kiem 1 phan tu tren cay nhi phan tim kiem
//     cout << "---------------Cau d---------------" << endl;
//     cout << "Nhap phan tu muon tim: ";
//     cin >> key;
//     cout << "Dia chi: " << findTNode(T, key) << endl;

//Cau e: Duyet cay nhi phan tim kiem
    cout << "---------------Cau e---------------" << endl;
    cout << "+NLR" << endl;
    preorder(T);
    cout << "\n\n+LNR" << endl;
    inorder(T);
    cout << "\n\n+LRN" << endl;
    postorder(T);

    return 0;
}