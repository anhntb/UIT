#include "question_a.cpp"
#include "question_b.cpp"
#include "question_c.cpp"
#include "question_d.cpp"
#include "question_e.cpp"

//*Câu a:
struct Node;
struct List;

//*Câu b:
Node* createNode(unsigned int);
void pushFront(List*, Node*);
void pushBack(List*, Node*);
void enterList_B(List*);
void enterList_F(List*);

//*Câu c:
bool isPrime(int);
void printPrime(List*);

//*Câu d:
void reverseList(List*);
void sortList(List*, bool asc); //default: ascending

//*Câu e:
void insertMidList(List*, int, Node*);
void addX_desList(List*, int);

void printList(List* a)
{
    Node* tmp = a->pHead;

    while(tmp != NULL)
    {
        cout << tmp->n << " ";
        tmp = tmp->pNext;
    }

    if(a->pHead == NULL)
        cout << "The list is empty!!!";
    cout << endl;
}

void deleteList(List* a)
{
    Node* tmp = a->pHead;
    while(tmp != NULL)
    {
        a->pHead = a->pHead->pNext;
        delete tmp;
        tmp = a->pHead;
    }
}

int main()
{
    List* a = new List; 
    enterList_F(a);

    //printPrime(a);
    //Node* a1 = createNode(7);
    //Node* a2 = createNode(8);
    //a1->pNext = a2;
    //a->pHead = a1; a->pTail = a2;
    sortList(a, 0);
    //printList(a); 

    addX_desList(a, 4);
    printList(a);

    return 0;
}