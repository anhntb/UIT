#include "MyLibrary.h"


void inputProcess(int n, PCB P[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter PID, Arrival Time, Burst Time: ";
        cin >> P[i].iPID >> P[i].iArrival >> P[i].iBurst;
    }
    cout << "------------------------------------------" << endl;
};

// print PID, Arrival Time, Burst Time, Waiting Time, Response Time, Turnaround Time
void printProcess(int n, PCB P[])
{
    string sP = "PID", sArr = "Arrival Time", sBur = "Burst Time";
    string sWait = "Waiting Time", sRes = "Response Time", sTaT = "Turnaround Time";

    sP.resize(10, ' ');
    sArr.resize(20, ' ');
    sBur.resize(20, ' ');
    sWait.resize(20, ' ');
    sRes.resize(20, ' ');
    sTaT.resize(20, ' ');
    cout << sP << sArr << sBur << sWait << sRes << sTaT << endl;

    for (int i = 0; i < n; i++)
    {
        sP = to_string(P[i].iPID);
        sArr = to_string(P[i].iArrival);
        sBur = to_string(P[i].iBurst);
        sWait = to_string(P[i].iWaiting);
        sRes = to_string(P[i].iResponse);
        sTaT = to_string(P[i].iTaT);

        sP.resize(10, ' ');
        sArr.resize(20, ' ');
        sBur.resize(20, ' ');
        sWait.resize(20, ' ');
        sRes.resize(20, ' ');
        sTaT.resize(20, ' ');

        cout << sP << sArr << sBur << sWait << sRes << sTaT << endl;
    }
    cout << "------------------------------------------" << endl;
};

double avgTurnaroundTime(int n, PCB P[])
{
    int iSum = 0;
    for (int i = 0; i < n; i++)
        iSum += P[i].iTaT;

    return (double)iSum / n;
}

double avgWaitingTime(int n, PCB P[])
{
    int iSum = 0;
    for (int i = 0; i < n; i++)
        iSum += P[i].iWaiting;

    return (double)iSum / n;
}

double avgResponseTime(int n, PCB P[])
{
    int iSum = 0;
    for (int i = 0; i < n; i++)
        iSum += P[i].iResponse;

    return (double)iSum / n;
}

void sortByArrival(int n, PCB P[])
{
    sort(P, P + n, [](PCB a, PCB b) {return a.iArrival < b.iArrival; });
}

void createProcess(int n, PCB* P)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        P[i].iPID = i + 1;
        P[i].iArrival = rand() % 21; // [0, 20]
        P[i].iBurst = (rand() % 11) + 2; // [2, 12]
    }
}
