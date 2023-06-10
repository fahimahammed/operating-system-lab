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
    vector<pair<ll, ll>> block;

    cin >> processNum;
    for (i = 0; i < processNum; i++){
        cin >> p;
        processSize.push_back(p);
    }

    cin >> blockNum;
    for (i = 1; i <= blockNum; i++){
        cin >> p;
        blockSize.push_back(p);
        block.push_back({p, i});
    }

    for (i = 0; i < processNum; i++){
        sort(block.begin(), block.end());
        sort(blockSize.begin(), blockSize.end());
        auto index = lower_bound(blockSize.begin(), blockSize.end(), processSize[i]);

        if(index == blockSize.end()){
            blockNo.push_back(-1);
        }
        else{
            ll newIndex = index - blockSize.begin();
            //cout<< newIndex << endl;
            blockNo.push_back(block[newIndex].second);
            block[newIndex].first -= processSize[i];
            blockSize[newIndex] -= processSize[i];
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
