#include "MyLibrary.h"

void SJF(int n, PCB P[])
{
    cout << "-------------------------------SJF Scheduling---------------------------" << endl;
    int completed = 0;
    bool* is_completed;
    int current_time = 0;

    is_completed = new bool[n];
    for (int i = 0; i < n; i++)
        is_completed[i] = false;

    while (completed != n)
    {
        int idx = -1;
        int min_busrt = INT_MAX;

        // Tiến trình có burst bé nhất (nếu burst bằng nhau thì chọn min arrival), đang xuất hiện trong hàng đợi
        for (int i = 0; i < n; i++)
        {
            if (P[i].iArrival <= current_time && is_completed[i] == 0) // Những tiến trình đang xuất hiện trong hàng đợi
            {
                if (P[i].iBurst < min_busrt) // busrt bé nhất
                {
                    min_busrt = P[i].iBurst;
                    idx = i;
                }

                if (P[i].iBurst == min_busrt) // busrt bằng nhau thì chọn min arrival
                    if (P[i].iArrival < P[idx].iArrival)
                        idx = i;
            }
        }

        if (idx != -1)
        {
            P[idx].iStart = current_time;
            current_time += P[idx].iBurst;
            P[idx].iFinish = current_time;
            P[idx].update();

            cout << P[idx].iStart << " -> " << P[idx].iFinish << " : " << "P" << idx << endl;

            is_completed[idx] = 1;
            completed++;
        }
        else
            current_time++;
    }

    cout << "-------------------------------------------------------------------------" << endl;

    delete[]is_completed;
}