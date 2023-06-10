#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

struct Process{
    int id;
    int brustTime;
};

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++){
        rem_bt[i] = bt[i];
    }

	int t = 0;
	while (1){
		bool done = true;

		for (int i = 0 ; i < n; i++){
			if (rem_bt[i] > 0){
				done = false; 

				if (rem_bt[i] > quantum){
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
		break;
	}
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]){
    for (int i = 0; i < n ; i++){
        tat[i] = bt[i] + wt[i];
    }
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int brustTime[] = {10, 5, 8};
    int quantum = 2;
    int waitingTime[n], turnaroundTime[n];
    findWaitingTime(processes, n, brustTime, waitingTime, quantum);
    findTurnAroundTime(n, brustTime, waitingTime, turnaroundTime);
    for(int i=0; i<n; i++){
        cout << waitingTime[i] << "  "<< turnaroundTime[i]<< endl;
    }
}
