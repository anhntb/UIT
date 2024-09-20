#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;

struct PCB
{
    int iPID;
    int iArrival, iBurst;
    int iStart = -1, iFinish = -1, iCurrent;
    int iWaiting = 0, iResponse = 0, iTaT = 0;

    void update()
    {
        iTaT = iFinish - iArrival;
        iResponse = iStart - iArrival;
        iWaiting = iTaT - iBurst;
    }
};

// ProcessSupport
void inputProcess(int n, PCB P[]);
void printProcess(int n, PCB P[]);

double avgTurnaroundTime(int n, PCB P[]);
double avgWaitingTime(int n, PCB P[]);
double avgResponseTime(int n, PCB P[]);

void sortByArrival(int n, PCB P[]);

void createProcess(int n, PCB* P);

// FCFS
void FCFS(int n, PCB P[]);

// SRT
void SRT(int n, PCB P[]);

// SJF
void SJF(int n, PCB P[]);