#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class NhaHang
{
private:
    string strTen;
    int iDGia;
    double dKhCach;

public:
    NhaHang(string ten = " ", int dg = 0, double kc = 0.0)
    {
        strTen = ten;
        
        if(dg < 0)
            iDGia = 0;
        else if(dg > 100)
            iDGia = 100;
        else
            iDGia = dg;

        if(kc < 0)
            dKhCach = 0;
        else
            dKhCach = kc;   
    }

    void setTen(string ten)
    {
        strTen = ten;
    }

    void setDGia(int dg)
    {
        if(dg < 0)
            iDGia = 0;
        else if(dg > 100)
            iDGia = 100;
        else
            iDGia = dg;
    }

    void setKhCach(double kc)
    {
        if(kc < 0)
            dKhCach = 0;
        else
            dKhCach = kc; 
    }

    string getTen() const
    {
        return strTen;
    }

    int getDGia() const
    {
        return iDGia;
    }

    double getKhCach() const
    {
        return dKhCach;
    }

    void inpInfor()
    {
        cout << "Ten nha hang: ";
        fflush(stdin);
        getline(cin, strTen);

        cout << "Danh gia: ";
        cin >> iDGia;

        cout << "Khoang cach den trung tam thanh pho: ";
        cin >> dKhCach;
    }

    void display() const
    {
        cout << "Ten nha hang: " << strTen << endl;
        cout << "Danh gia: " << iDGia << endl;
        cout << "Khoang cach den trung tam thanh pho: " << dKhCach << endl;
    }
};

struct Node
{
    NhaHang data;
    Node* pNext = NULL;
};

struct List
{
    Node* pHead = NULL;
    Node* pTail = NULL;
};

Node* createNode(const NhaHang &a)
{
    Node* tmp = new Node;
    if(tmp == NULL)
    {
        cout << "Cap phat bo nho that bai!" << endl;
        exit(1);
    }
    tmp->data = a;
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

void inpList(List &l, int n = 10) //mặc định nhập 10 Node
{
    NhaHang tmp;
    for(int i=0; i<n; i++)
    {
        tmp.inpInfor();
        cout << endl;
        addNode(l, createNode(tmp));
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
        tmp->data.display();
        cout << endl;
        tmp = tmp->pNext;
    }
}

void printDGiaTren90(const List &l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* tmp = l.pHead;
    while(tmp != NULL)
    {
        if(tmp->data.getDGia() >= 90)
        {
            tmp->data.display();
            cout << endl;
        }
        tmp = tmp->pNext;
    }
}

bool myCompare(const NhaHang &a, const NhaHang &b) //true: a.iDGia > b.iDGia 
{                                                  // or (a.iDGia = b.iDGia) && (a.dKhCach <= b.dKhCach)
    if(a.getDGia() > b.getDGia())
        return true;

    if(a.getDGia() == b.getDGia() && a.getKhCach() <= b.getKhCach())
        return true;

    return false;
}

void sortList(List &l)
{
    if(l.pHead == NULL) //List rỗng
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    if(l.pHead->pNext == NULL) //chỉ có 1 Node
        return;

    Node* pH = l.pHead;
    Node* pNext_H = NULL; //Node ngay trước pH
    do
    {
        if(!myCompare(pH->data, pH->pNext->data)) //swap Node pH và Node kề bên
        {
            Node* tmp = pH;
            pH = pH->pNext;
            tmp->pNext = pH->pNext;
            pH->pNext = tmp;
        }

        Node* i = pH->pNext;
        while(i->pNext != NULL) //i: Node ngay trước Node cần so sánh
        {
            if(!myCompare(pH->data, i->pNext->data))
            {
                Node* tmp = pH->pNext;

                //thay đổi pNext của 2 Node cần swap
                pH->pNext = i->pNext->pNext;
                i->pNext->pNext = tmp;

                //cập nhật lại pH
                tmp = pH;
                pH = i->pNext;
                i->pNext = tmp;
            }
            i = i->pNext;
        } //kết thúc khi i ở Node cuối
        l.pTail = i;

        if(pNext_H == NULL)
        {
            pNext_H = pH;
            l.pHead = pH;
        }
        else
        {
            pNext_H->pNext = pH;
            pNext_H = pH;
        }
        pH = pH->pNext;
    }while(pH != l.pTail);
}

int main()
{
    List list;

    // NhaHang nh1("1",90,1.5);
    // NhaHang nh2("2",20,2.5);
    // NhaHang nh3("3",30,3.5);
    // NhaHang nh4("4",70,4.5);
    // NhaHang nh5("5",30,5.5);

    // Node* n1 = new Node;
    // n1->data = nh1;
    // Node* n2 = new Node;
    // n2->data = nh2;
    // Node* n3 = new Node;
    // n3->data = nh3;
    // Node* n4 = new Node;
    // n4->data = nh4;
    // Node* n5 = new Node;
    // n5->data = nh5;

    // list.pHead = n1;
    // list.pTail = n5;
    // n1->pNext = n2;
    // n2->pNext = n3;
    // n3->pNext = n4;
    // n4->pNext = n5;

//Câu b:
    inpList(list);
    cout << endl;

//Câu c:
    cout << "Nha hang co danh gia >= 90" << endl;
    printDGiaTren90(list);
    cout << endl;

//Cau d:
    cout << "---------Danh sach nha hang---------" << endl;
    sortList(list);
    outList(list);

    return 0;
}