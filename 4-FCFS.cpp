#include<iostream>
using namespace std;
 
void fcfsScheduling(int p[], int n, int bt[]){
    int waitingTime[n], turnTime[n], totalWt=0, totalTurn=0; 
 
    waitingTime[0] = 0;
    cout<<endl<<"Process"<<"\t"<<"Brust Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turn Around Time"<<endl;
    cout<<"-------+---------------+---------------+-----------------+"<<endl;
    for(int i=0; i<n; i++){
        if(i>0){
           waitingTime[i] = waitingTime[i-1] + bt[i-1];
        }
        totalWt += waitingTime[i];
        turnTime[i] = bt[i] + waitingTime[i];
        totalTurn += turnTime[i];
 
        cout<<"P"<<p[i]<<" \t"<<bt[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnTime[i]<<endl;
    }
    cout<<endl<<"Average waiting time: "<< (float)totalWt/ (float)n << endl;
    cout<<"Average turn around time: "<< (float)totalTurn/ (float)n << endl << endl;
}
int main(){
    int n;
    cout<<"Enter the process number: ";
    cin>>n;
    int process[n], brustTime[n];
    for(int i=0; i<n; i++){
        cout<<"Enter process number & brust time : ";
        cin>>process[i]>>brustTime[i];
    }
    fcfsScheduling(process, n, brustTime);
    return 0;
}