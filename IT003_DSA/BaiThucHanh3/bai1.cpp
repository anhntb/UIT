#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class SinhVien
{
private:
    string strMSSV;
    string strTen;
    double dDTB;

public:
    SinhVien(string mssv = " ", string ten = " ", double dtb = 0.0)
    {
        strMSSV = mssv;
        strTen = ten;

        if(dtb < 0)
            dDTB = 0;
        else if(dtb > 10)
            dDTB = 10;
        else
            dDTB = dtb;
    }

    void setMSSV(string mssv)
    {
        strMSSV = mssv;
    }

    void setTen(string ten)
    {
        strTen = ten;
    }

    void setDTB(double dtb)
    {
        if(dtb < 0)
            dDTB = 0;
        else if(dtb > 10)
            dDTB = 10;
        else
            dDTB = dtb;
    }

    string getMSSV() const
    {
        return strMSSV;
    }

    string getTen() const
    {
        return strTen;
    }

    double getDTB() const
    {
        return dDTB;
    }

    string xepLoai() const
    {
        if(dDTB <= 3.6) return "Kem";
        if(dDTB < 5.0) return "Yeu";
        if(dDTB < 6.5) return "Trung binh";
        if(dDTB < 7.0) return "Trung binh kha";
        if(dDTB < 8.0) return "Kha";
        if(dDTB < 9.0) return "Gioi";
        return "Xuat sac";
    }

    void setInfor()
    {
        fflush(stdin);
        cout << "Ma so sinh vien: ";
        getline(cin, strMSSV);
        
        cout << "Ho ten: ";
        getline(cin, strTen);

        cout << "Diem trung binh: ";
        cin >> dDTB;
    }

    void display() const
    {
        cout << "Ma so sinh vien: " << strMSSV << endl;
        cout << "Ho ten: " << strTen << endl;
        cout << "Diem trung binh: " << dDTB << endl;
        cout << "Xep loai: " << xepLoai() << endl;
    }
};

struct Node
{
    SinhVien data;
    Node* pNext = NULL;
};

struct List
{
    Node* pHead = NULL;
    Node* pTail = NULL;
};

Node* createNode(const SinhVien &a)
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
    if(l.pHead == NULL && l.pTail == NULL)
    {
        l.pHead = a;
        l.pTail = a;
    }
    else
    {
        a->pNext = l.pHead;
        l.pHead = a;
    }
}

void inpList(List &l)
{
    SinhVien tmp;
    while(true)
    {
        tmp.setInfor();
        cout << endl;

        if(tmp.getTen() == " ")
            break;
        else
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

bool findSV(const List &l, string mssv)
{
    if(l.pHead == NULL)
        return false;

    Node* tmp = l.pHead;
    while(tmp != NULL)
    {
        if(tmp->data.getMSSV() == mssv)
            return true;
        tmp = tmp->pNext;
    }
    return false;
}

Node* deleteNode(Node* a) //Xóa Node và trả về Node liền sau
{
    if(a == NULL)
        return NULL;

    Node* tmp = a->pNext;
    delete a;
    return tmp;
}

bool deleteSV(List &l, string mssv) //true: tìm thấy và đã thực hiện xóa sinh viên
{                                   //false: không tìm thấy sinh viên
    if(l.pHead == NULL)
        return false;

    if(l.pHead->data.getMSSV() == mssv) //xóa Node đầu
    {
        l.pHead = deleteNode(l.pHead);
        return true;
    }

    Node* tmp = l.pHead;
    while(tmp != l.pTail) //duyệt đến Node gần cuối
    {
        if(tmp->pNext->data.getMSSV() == mssv) //so sánh dữ liệu Node kế
        { 
            tmp->pNext = deleteNode(tmp->pNext);
            return true;
        }
        tmp = tmp->pNext;
    }

    return false;
}

void printDTBTren5(const List &l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* tmp = l.pHead;
    while(tmp != NULL)
    {
        if(tmp->data.getDTB() >= 5)
        {
            tmp->data.display();
            cout << endl;
        }
        tmp = tmp->pNext;
    }
}

void sortList(List &l) //tăng dần
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
        if(pH->data.getDTB() > pH->pNext->data.getDTB()) //swap Node pH và Node kề bên
        {
            Node* tmp = pH;
            pH = pH->pNext;
            tmp->pNext = pH->pNext;
            pH->pNext = tmp;
        }

        Node* i = pH->pNext;
        while(i->pNext != NULL) //i: Node ngay trước Node cần so sánh
        {
            if(pH->data.getDTB() > i->pNext->data.getDTB())
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

    // SinhVien sv1("1","1",9);
    // SinhVien sv2("2","2",2);
    // SinhVien sv3("3","3",3);
    // SinhVien sv4("4","4",7);
    // SinhVien sv5("5","5",3);

    // Node* n1 = new Node;
    // n1->data = sv1;
    // Node* n2 = new Node;
    // n2->data = sv2;
    // Node* n3 = new Node;
    // n3->data = sv3;
    // Node* n4 = new Node;
    // n4->data = sv4;
    // Node* n5 = new Node;
    // n5->data = sv5;

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
    string mssv;
    fflush(stdin);
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << (findSV(list, mssv) ? "Tim thay!" : "Khong tim thay!") << endl << endl;

//Câu d:
    fflush(stdin);
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << (deleteSV(list, mssv) ? "Da xoa!" : "Khong co sinh vien nay!") << endl << endl;

//Cau e:
    cout << "Sinh vien co diem trung binh >= 5" << endl;
    printDTBTren5(list);
    cout << endl;

//Cau f,g:
    cout << "-----------Danh sach sinh vien-----------" << endl;
    sortList(list);
    outList(list);

    return 0;
}