//#include <iostream>
//#include "MyLibrary.h"
//
//using namespace std;
//
//int main()
//{
//    int n;
//    PCB* P;
//
//    cout << "Enter total number of processes: ";
//    cin >> n;
//
//    P = new PCB[n];
//    createProcess(n, P);
////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    int quantum_t;
//    cout << "Enter quantum time: ";
//    cin >> quantum_t;
//
//    PCB* temp;
//    temp = new PCB[n];
//    for(int i = 0; i < n; i++)
//    {
//        temp[i].iPID = P[i].iPID;
//        temp[i].iArrival = P[i].iArrival;
//        temp[i].iBurst = P[i].iBurst;
//    }
//
//    int* bt_remaining;
//    int current_time = 0;
//    int completed = 0;
//
//    bt_remaining = new int[n];
//
//    for (int i = 0; i < n; i++)
//        bt_remaining[i] = P[i].iBurst;
//
//    sortByArrival(n, temp);
//    current_time = temp[0].iArrival;
//
//    while (completed != n)
//    {
//        // Tiến trình chạy lần đầu tiên
//        if (temp[0].iBurst == bt_remaining[temp[0].iPID - 1])
//        {
//            temp[0].iStart = current_time;
//            cout << "start = " << temp[0].iStart << endl;
//        }
//        cout << current_time << "->";
//        if (bt_remaining[temp[0].iPID - 1] >= quantum_t)
//        {
//            bt_remaining[temp[0].iPID - 1] -= quantum_t;
//            current_time += quantum_t;
//        }
//        else
//        {
//            current_time += bt_remaining[temp[0].iPID - 1];
//            bt_remaining[temp[0].iPID - 1] = 0;
//        }
//        cout << current_time << ": P" << temp[0].iPID << endl;
//
//        if (bt_remaining[temp[0].iPID - 1] == 0)
//        {
//            temp[0].iFinish = current_time;
//            cout << "finish = " << temp[0].iFinish << endl;
//            completed++;
//        }
//
//        // Đưa tiến trình đã chạy về cuối hàng đợi
//        PCB temp_p;
//        temp_p.iPID = temp[0].iPID;
//        temp_p.iArrival = temp[0].iArrival;
//        temp_p.iBurst = temp[0].iBurst;
//        temp_p.iStart = temp[0].iStart;
//        temp_p.iFinish = temp[0].iFinish;
//        int idx = -1;
//        for (int i = 0; i < n - 1; i++)
//            if (temp[i + 1].iArrival <= current_time)
//            {
//                temp[i].iPID = temp[i+1].iPID;
//                temp[i].iArrival = temp[i+1].iArrival;
//                temp[i].iBurst = temp[i+1].iBurst;
//                temp[i].iStart = temp[i+1].iStart;
//                temp[i].iFinish = temp[i+1].iFinish;
//                idx = i + 1;
//            }
//            else
//                break;
//        if (idx != -1)
//        {
//            temp[idx].iPID = temp_p.iPID;
//            temp[idx].iArrival = temp_p.iArrival;
//            temp[idx].iBurst = temp_p.iBurst;
//            temp[idx].iStart = temp_p.iStart;
//            temp[idx].iFinish = temp_p.iFinish;
//        }
//    }
//
//    // Lưu dữ liệu vào mảng ban đầu
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++)
//            if (P[i].iPID == temp[j].iPID)
//            {
//                P[i].iStart = temp[j].iStart;
//                P[i].iFinish = temp[j].iFinish;
//                P[i].update();
//                break;
//            }
//
//    //Output
//    printProcess(n, P);
//
//    cout << "\nAverage Turn Around Time = " << avgTurnaroundTime(n, P);
//    cout << "\nAverage Waiting Time = " << avgWaitingTime(n, P);
//    cout << "\nAverage Response Time = " << avgResponseTime(n, P) << endl;
//
//    delete[]P;
//    
//    delete[]bt_remaining;
//    delete[]temp;
//    return 0;
//}

#include <iostream>
#include "MyLibrary.h"

using namespace std;

int main()
{
    int n;
    PCB* P;

    cout << "Enter total number of processes: ";
    cin >> n;

    P = new PCB[n];
    createProcess(n, P);
    
    SRT(n, P);

    //Output
    printProcess(n, P);

    cout << "\nAverage Turn Around Time = " << avgTurnaroundTime(n, P);
    cout << "\nAverage Waiting Time = " << avgWaitingTime(n, P);
    cout << "\nAverage Response Time = " << avgResponseTime(n, P) << endl;

    delete[]P;

    return 0;
}