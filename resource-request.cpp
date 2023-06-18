#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;                // Process ID
    int typeA;              // Number of resources of type A allocated to the process
    int typeB;              // Number of resources of type B allocated to the process
    int typeC;              // Number of resources of type C allocated to the process
    int requestTypeA;       // Number of resources of type A requested by the process
    int requestTypeB;       // Number of resources of type B requested by the process
    int requestTypeC;       // Number of resources of type C requested by the process
    bool isCompleted = false;   // Flag indicating whether the process has completed its execution
};

struct Resource {
    int typeA;              // Number of available resources of type A
    int typeB;              // Number of available resources of type B
    int typeC;              // Number of available resources of type C
};

void check(int n, Resource& r, vector<Process>& p) {
    int completed = 0, id = -1;
    vector<int> safeSequence;
    while (completed != n) {
        cout << "Resources_Avaiable: ";
        cout << r.typeA << ' ' << r.typeB << ' ' << r.typeC << " [" << id << "]" << endl;
        bool isDeadlock = true;
        for (int i = 0; i < n; i++) {
            if (!p[i].isCompleted) {
                if (p[i].requestTypeA <= r.typeA && p[i].requestTypeB <= r.typeB && p[i].requestTypeC <= r.typeC) {
                    id = p[i].pid;
                    p[i].isCompleted = true;
                    safeSequence.push_back(p[i].pid);
                    isDeadlock = false;
                    completed++;
                    r.typeA += p[i].typeA;
                    r.typeB += p[i].typeB;
                    r.typeC += p[i].typeC;
                    break;
                }
            }
        }
        if (isDeadlock) {
            cout << endl << "Unsafe, Can't request...!";
            return;
        }
    }

    cout << endl << "Can request\nOne Safe Sequence: ";
    for (int x : safeSequence) {
        cout << x << " ";
    }
}

int main() {
    freopen("deadlock.txt", "r", stdin);

    int n;                      // Number of processes
    cin >> n;
    Resource r;                 // Resource availability
    cin >> r.typeA >> r.typeB >> r.typeC;

    vector<Process> p(n);       // Vector to store the processes
    for (int i = 0; i < n; i++) {
        cin >> p[i].typeA >> p[i].typeB >> p[i].typeC >> p[i].requestTypeA >> p[i].requestTypeB >> p[i].requestTypeC;
        p[i].pid = i;
    }

    check(n, r, p);
    return 0;
}
