#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int brustTime;
    int priority;
};

int main()
{
    int n;
    cout << "Enter the process number: ";
    cin >> n;

    vector<Process> processes(n);
    for(int i = 0; i<n;  i++){
        cout << "Enter the id, burst time, and priority for process "<< i+1 << ": ";
        cin >> processes[i].id >> processes[i].brustTime >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), [](const Process& a, Process& b){
        return a.priority > b.priority;
    });

    vector<int> waitingTimes(n);
    waitingTimes[0] = 0;
    for (int i=1; i<n; i++){
        waitingTimes[i] = waitingTimes[i-1] + processes[i-1].brustTime;
    }

    vector<int> turnaroundTime(n);
    for(int i=0; i<n; i++){
        turnaroundTime[i] = waitingTimes[i] + processes[i].brustTime;
    }

    for(int i=0; i<n; i++){
        cout << "Process " << processes[i].id << " has waiting time: "<< waitingTimes[i] << " and turnaround time: "<< turnaroundTime[i] << endl;
    }
    return 0;
}

/**
Enter the process number: 3
Enter the id, burst time, and priority for process 1: 1 10 2
Enter the id, burst time, and priority for process 2: 2 5 0
Enter the id, burst time, and priority for process 3: 3 8 1
Process 1 has waiting time: 0 and turnaround time: 10
Process 3 has waiting time: 10 and turnaround time: 18
Process 2 has waiting time: 18 and turnaround time: 23
*/