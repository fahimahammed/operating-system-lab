#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

list<int> l;
unordered_map<int, pair<int, list<int>::iterator>> m;
int pageFrame = 3;
int pageFault = 0;
int pageCount = 0;

bool checkPageHit(int n)
{
    if (m.find(n) != m.end()) {
        int currentFrequency = m[n].first;
        l.erase(m[n].second);
        l.push_front(n);
        m[n] = make_pair(currentFrequency + 1, l.begin());
        return true;
    } else if (l.size() == pageFrame) {
        int leastFrequency = m[l.back()].first;
        m.erase(l.back());
        l.pop_back();
        pageFault++;
    }
    l.push_front(n);
    m[n] = make_pair(1, l.begin());
    pageFault++;
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
