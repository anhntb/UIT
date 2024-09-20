#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Student
{
private:
    string strStuID; //*Student idenity || student code
    string strName;
    int iMathScr; //*Math score
    int iLiterScr; //*Literature score
    int iEngScr; //*English score

public:
    Student(string strStuID = "", string strName = "", int iMathScr = 0, int iLiterScr = 0, int iEngScr = 0)
    {
        this->strStuID = strStuID;
        this->strName = strName;
        this->iMathScr = iMathScr;
        this->iLiterScr = iLiterScr;
        this->iEngScr = iEngScr;

        if(iMathScr<0) iMathScr=0;
        if(iMathScr>10) iMathScr=10;

        if(iLiterScr<0) iLiterScr=0;
        if(iLiterScr>10) iLiterScr=10;

        if(iEngScr<0) iEngScr=0;
        if(iEngScr>10) iEngScr=10;
    }

    void setStrStuID(string strStuID)
    {
        this->strStuID = strStuID;
    }

    string getStrStuID()
    {
        return strStuID;
    }

    void setStrName(string strName)
    {
        this->strName = strName;
    }

    string getStrName()
    {
        return strName;
    }

    void setIMathScr(int iMathScr)
    {
        this->iMathScr = iMathScr;
        if(iMathScr<0) this->iMathScr=0;
        if(iMathScr>10) this->iMathScr=10;
    }

    int getIMathScr()
    {
        return iMathScr;
    }

    void setILiterScr(int iLiterScr)
    {
        this->iLiterScr = iLiterScr;
        if(iLiterScr<0) this->iLiterScr=0;
        if(iLiterScr>10) this->iLiterScr=10;
    }

    int getILiterScr()
    {
        return iLiterScr;
    }

    void setIEngScr(int iEngScr)
    {
        this->iEngScr = iEngScr;
        if(iEngScr<0) this->iEngScr=0;
        if(iEngScr>10) this->iEngScr=10;
    }

    int getIEngScr()
    {
        return iEngScr;
    }

    double average()
    {
        return (iMathScr + iLiterScr + iEngScr)/3.;
    }

    void getData()
    {
        cout << "Student ID: ";
        fflush(stdin);
        getline(cin, strStuID);

        cout << "Full name: ";
        fflush(stdin);
        getline(cin, strName);

        cout << "Math score: ";
        cin >> iMathScr;
        setIMathScr(iMathScr);

        cout << "Literature score: ";
        cin >> iLiterScr;
        setILiterScr(iLiterScr);

        cout << "English score: ";
        cin >> iEngScr;
        setIEngScr(iEngScr);
    }

    void display()
    {
        cout << "Student ID: " << strStuID << endl;
        cout << "Full name: " << strName << endl;
        cout << "Math score: " << iMathScr << endl;
        cout << "Literature score: " << iLiterScr << endl;
        cout << "English score: " << iEngScr << endl;
        cout << "Average: " << average() << endl;
    }
};

class ClassRoom
{
private:
    string strClassID;
    int iNumOfStu; //*Number of students
    Student* listOfStu; //*List of students

public:
    ClassRoom(string strClassID = "", int iNumOfStu = 0)
    {
        this->strClassID = strClassID;
        this->iNumOfStu = iNumOfStu;
        listOfStu = new Student[iNumOfStu];
    }

    ~ClassRoom()
    {
        delete[] listOfStu;
    }

    void setStrClassID(string strClassID)
    {
        this->strClassID = strClassID;
    }

    string getStrClassID()
    {
        return strClassID;
    }

    int getINumOfStu()
    {
        return iNumOfStu;
    }

    void getData()
    {
        cout << "Enter the class ID: ";
        fflush(stdin);
        getline(cin, strClassID);

        cout << "Enter the number of students: ";
        cin >> iNumOfStu;
        if(iNumOfStu < 0) iNumOfStu=0;

        listOfStu = new Student[iNumOfStu];
        for(int i=0; i<iNumOfStu; i++)
        {
            cout << "\n----------Student Information " << i+1 << "----------" << endl;
            listOfStu[i].getData();
        }
    }

    void display()
    {
        cout << "-------------------------------------Class " + strClassID + "-------------------------------------" << endl;
        for(int i=0; i<iNumOfStu; i++)
        {
            cout << "+   Student " << i+1 << endl;
            listOfStu[i].display();
            cout << endl;
        }
    }
};

class School
{
private:
    string strSchoolID;
    int iNumOfClass;
    ClassRoom* listOfClass;

public:
    School(string strSchoolID = "", int iNumOfClass = 0)
    {
        this->strSchoolID = strSchoolID;
        this->iNumOfClass = iNumOfClass;
    }

    ~School()
    {
        delete[] listOfClass;
    }

    void setStrSchoolID(string strSchoolID)
    {
        this->strSchoolID = strSchoolID;
    }

    string getStrSchoolID()
    {
        return strSchoolID;
    }

    int getINumOfClass()
    {
        return iNumOfClass;
    }

    void getData()
    {
        cout << "Enter the school ID: ";
        fflush(stdin);
        getline(cin, strSchoolID);

        cout << "Enter the number of classes: ";
        cin >> iNumOfClass;
        if(iNumOfClass < 0) iNumOfClass=0;

        listOfClass = new ClassRoom[iNumOfClass];
        for(int i=0; i<iNumOfClass; i++)
        {
            cout << "\n**********Class Information " << i+1 << "**********" << endl;
            listOfClass[i].getData();
        }
    }

    void display()
    {
        cout << "====================================School " + strSchoolID + "====================================" << endl;
        for(int i=0; i<iNumOfClass; i++)
        {
            listOfClass[i].display();
            cout << endl << endl;
        }
    }
};

int main()
{
    School a;
    a.getData();
    a.display();

    return 0;
}