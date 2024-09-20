// ProcessScheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyLibrary.h"


// Chỉ đúng khi trong hàng đợi luôn có tiến trình
void FCFS(int n, PCB P[])
{
    cout << "-------------------------------FCFS Scheduling---------------------------" << endl;

    // sort by arrival time
    sort(P, P + n, [](PCB a, PCB b) {return a.iArrival < b.iArrival; });

    int iMoment = P[0].iArrival;
    for (int i = 0; i < n; i++)
    {
        cout << iMoment;

        if (i == 0)
            P[i].iStart = P[i].iArrival;
        else
            P[i].iStart = P[i - 1].iFinish;

        P[i].iFinish = P[i].iStart + P[i].iBurst;
        P[i].update();

        iMoment = P[i].iFinish;
        cout << "->" << iMoment << " : " << P[i].iPID << endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// TiP for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
