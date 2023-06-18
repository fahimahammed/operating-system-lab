#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int pageFrame = 3;
int pageFault = 0;
int queueLength = 0;

bool checkPageHit(int n)
{
    queue<int> tq;
    tq = q;
    while(!tq.empty()){
        int top = tq.front();
        tq.pop();
        if(top == n){
            return true;
        }
    }
    if(queueLength == pageFrame){
        q.pop();
        q.push(n);
    }
    else{
        q.push(n);
        queueLength++;
    }
    pageFault++;
    return false;
}

void printQueue()
{
    queue<int>currentQ;
    currentQ = q;
    while(!currentQ.empty()){
        int x = currentQ.front();
        currentQ.pop();
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int count=0;
    while(1){
        int n;
        cin >> n;
        if(n<0) break;
        count++;
        if(checkPageHit(n)){
            cout << "Hit" << endl;
        }
        else {
            cout << "Miss" << endl;
        }
        cout << "Page Fault: " << pageFault << endl;
        cout << "Page Hit: " << count - pageFault << endl;
        cout << "Current Queue: ";
        printQueue();
        
    }
    return 0;
}
