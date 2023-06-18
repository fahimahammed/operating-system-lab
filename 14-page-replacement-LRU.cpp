#include <bits/stdc++.h>
using namespace std;

list<int> l;
unordered_map<int, list<int>::iterator> m;
int pageFrame = 3;
int pageFault = 0;
int pageCount = 0;

bool checkPageHit(int n)
{
    if (m.find(n) != m.end()) {
        l.erase(m[n]);
        l.push_front(n);
        m[n] = l.begin();
        return true;
    } else if (l.size() == pageFrame) {
        int leastRecentlyUsed = l.back();
        l.pop_back();
        m.erase(leastRecentlyUsed);
    }
    // cout<< "3-----"<<endl;
    l.push_front(n);
    m[n] = l.begin();
    pageFault++;
    //cout<< "4-----"<<endl;
    return false;
}

void printList()
{
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    while (1) {
        int n;
        cin >> n;
        if (n < 0)
            break;
        pageCount++;
        if (checkPageHit(n)) {
            cout << "Hit" << endl;
        } else {
            cout << "Miss" << endl;
        }

        cout << "Page Fault: " << pageFault << endl;
        cout << "Page Hit: " << pageCount - pageFault << endl;
        cout << "Current List: ";
        printList();
    }

    return 0;
}
