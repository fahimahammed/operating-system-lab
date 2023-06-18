#include <bits/stdc++.h>
#include <unistd.h> 
using namespace std;

int main()
{
    char dir[2048];
    getcwd(dir, sizeof(dir));
    cout << dir << endl;
    return 0;
}