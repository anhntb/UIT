#include "MyLibrary.h"

void SRT(int n, PCB P[])
{
    cout << "-------------------------------SRT Scheduling---------------------------" << endl;

    int* bt_remaining;
    bool* is_completed;
    bool is_first_process = true;
    int current_time = 0;
    int completed = 0;
    //int prev = 0;

    bt_remaining = new int[n];
    is_completed = new bool[n];

    for (int i = 0; i < n; i++)
    {
        bt_remaining[i] = P[i].iBurst;
        is_completed[i] = false;
    }

    while (completed != n)
    {
        //find process with min_burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (P[i].iArrival <= current_time && is_completed[i] == false)
            {
                if (bt_remaining[i] < minimum)
                {
                    minimum = bt_remaining[i];
                    min_index = i;
                }
                if (bt_remaining[i] == minimum)
                    if (P[i].iArrival < P[min_index].iArrival)
                        min_index = i;
            }
        }

        if (min_index == -1)
            current_time++;
        else
        {
            if (bt_remaining[min_index] == P[min_index].iBurst)
            {
                P[min_index].iStart = current_time;
                is_first_process = false;
            }
            bt_remaining[min_index]--;
            current_time++;
            //prev = current_time;

            if (bt_remaining[min_index] == 0)
            {
                P[min_index].iFinish = current_time;
                P[min_index].update();

                completed++;
                is_completed[min_index] = true;
            }
        }
    }

    cout << "-------------------------------------------------------------------------" << endl;

    delete[]bt_remaining;
    delete[]is_completed;
}