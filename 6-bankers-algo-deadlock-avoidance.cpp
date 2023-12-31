#include<iostream>
using namespace std;

int main()
{
    int processNum, resourceNum, i, j, k;
    processNum = 5;
    resourceNum = 3;
    int allocation[processNum][resourceNum] = {{0, 1, 0},
                                               {2, 0, 0},
                                               {3, 0, 2},
                                               {2, 1, 1},
                                               {0, 0, 2}};
    int max[processNum][resourceNum] = {{7, 5, 3},
                                        {3, 2, 2},
                                        {9, 0, 2},
                                        {2, 2, 2},
                                        {4, 3, 3}};
    int available[resourceNum] = {3, 3, 2};

    int finish[processNum], ans[processNum], index = 0, need[processNum][resourceNum];

    for(i = 0; i<processNum; i++){
        finish[i] = 0;
    }

    for(i = 0; i<processNum; i++){
        for(j = 0; j<resourceNum; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int y = 0;
    for(k = 0; k<processNum; k++){
        for(i=0; i<processNum; i++){
            if(finish[i] == 0){
                int flag = 0;
                for(j = 0; j<resourceNum; j++){
                    if(need[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    ans[index++] = i;
                    for(y = 0; y<resourceNum; y++){
                        available[y] = available[y] + allocation[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for(i = 0; i<processNum; i++){
        if(finish[i] == 0){
            flag = 0;
            cout << "The given sequence is not safe"<< endl;
            break;
        }
    }

    if(flag == 1){
        cout << "Safe sequence is ";
        for(i = 0; i< processNum-1; i++){
            cout<< " P" << ans[i] << " >";
        }
        cout << " P" << ans[processNum-1] << endl;
    }
    return 0;
}