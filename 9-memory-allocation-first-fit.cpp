#include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);
    ll i, j, p, processNum, blockNum;
    bool flag = true;
    vector<ll> processSize, blockNo, blockSize;

    cin >> processNum;
    for (i = 0; i < processNum; i++){
        cin >> p;
        processSize.push_back(p);
    }

    cin >> blockNum;
    for (i = 1; i <= blockNum; i++){
        cin >> p;
        blockSize.push_back(p);
    }

    for (i = 0; i < processNum; i++){
        flag = true;
        for (j = 0; j < blockNum; j++){
            if (blockSize[j] >= processSize[i])
            {
                flag = false;
                blockNo.push_back(j + 1);
                blockSize[j] -= processSize[i];
                break;
            }
        }

        if (flag){
            blockNo.push_back(-1);
        }
    }

    cout << "Process No" << "\tProcess size" << "\tBlock No" << endl;

    for (i = 0; i < processNum; i++){
        cout << "  " << i + 1 << "    "<< "\t\t" << processSize[i] << "\t\t";

        (blockNo[i] == -1) ? cout << "Not Allocated" : cout << blockNo[i];
        cout << endl;
    }

    return 0;
}


// output:
/**
 * Process No      Process size    Block No
  1             212             2
  2             417             5
  3             112             2
  4             426             Not Allocated
*/