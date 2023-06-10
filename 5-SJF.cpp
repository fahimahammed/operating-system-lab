#include <iostream>
#include <algorithm>
using namespace std;

struct process
{
    int pid, arrivalTime, brustTime, waitingTime, completionTime, turnAroundTime;
};

bool compare(process a, process b)
{
    return a.brustTime < b.brustTime;
}

int main()
{
    int n, i, j;
    float awt = 0, atat = 0;
    process p[20];

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter the arrival time for process P" << p[i].pid << ": ";
        cin >> p[i].arrivalTime;
        cout << "Enter the burst time for process P" << p[i].pid << ": ";
        cin >> p[i].brustTime;
    }

    // Sorting the processes by arrival time and burst time using the compare function
    sort(p, p + n, [](process a, process b){
        if (a.arrivalTime == b.arrivalTime){
            return a.brustTime < b.brustTime;
        }
        return a.arrivalTime < b.arrivalTime; 
    });

    // Calculating waiting time for each process
    p[0].waitingTime = 0;
    for (i = 1; i < n; i++)
    {
        p[i].waitingTime = 0;
        for (j = 0; j < i; j++){
            p[i].waitingTime += p[j].brustTime;
        }
        p[i].waitingTime -= p[i].arrivalTime - p[0].arrivalTime;
        cout<<"Waiting time: "<<p[i].waitingTime<<endl;
    }

    // Calculating completion time for each process
    p[0].completionTime = p[0].brustTime + p[0].arrivalTime;
    for (i = 1; i < n; i++){
        p[i].completionTime = max(p[i].arrivalTime, p[i - 1].completionTime) + p[i].brustTime;
    }

    // Calculating turnaround time for each process
    for (i = 0; i < n; i++){
        p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
    }

    // Calculating average waiting time and average turnaround time
    for (i = 0; i < n; i++){
        awt += p[i].waitingTime;
        atat += p[i].turnAroundTime;
    }
    awt /= n;
    atat /= n;

    // Printing the output
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time";
    for (i = 0; i < n; i++){
        cout << "\nP" << p[i].pid << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].brustTime << "\t\t" << p[i].waitingTime << "\t\t" << p[i].completionTime << "\t\t" << p[i].turnAroundTime;
    }

    cout << "\n\nAverage Waiting Time: " << awt;
    cout << "\nAverage Turnaround Time: " << atat;

    return 0;
}