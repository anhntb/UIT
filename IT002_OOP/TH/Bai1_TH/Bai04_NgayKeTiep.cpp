#include <iostream>

using namespace std;

/*
Bài 4: Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
+Input: 1 ngày (Ngày / tháng / năm)
+Output: ngày kế tiếp
*/
struct Date
{
    int iDay;
    int iMonth;
    int iYear;

    Date(int d=1, int m=1, int y=1) : iDay(d), iMonth(m), iYear(y)
    {
        Input();
    }

    void Input()
    {
        while(!DateCheck())
        {
            cout << "Ngay sai!!!\n" << "Nhap lai: ";
            cin >> iDay >> iMonth >> iYear;
        }
    }

    void Display()
    {
        cout << iDay << "/" << iMonth << "/" << iYear << endl;
    }

    bool LeapYear()
    {
        return (iYear%400 == 0) || (iYear%4 == 0 && iYear%100 != 0);
    }

    bool DateCheck()
    {
        if(iYear<0 || iMonth<0 || iMonth>12 || iDay<0 || iDay>31) 
            return 0;
        
        switch(iMonth)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 1;

            case 2:
                if(LeapYear())
                {
                    return iDay<=29;
                }
                return iDay<=28;

            default:
                return iDay<=30;
        }
    }

    void NextDate()
    {
        iDay++;
        if(!DateCheck())
        {
            iDay=1;
            iMonth++;
            if(!DateCheck())
            {
                iMonth=1;
                iYear++;
            }
        }
    }
};

int main()
{
    Date a(1, 2, 3);
    cout << "Ngay hien tai: ";
    a.Display();

    a.NextDate();
    cout << "Ngay ke tiep: ";
    a.Display();

    return 0;
}