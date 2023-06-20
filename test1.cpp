#include <bits/stdc++.h>
using namespace std;
int n, p, b, q, turn = 0, t = 0;
map<int, int> TurnOver;
vector<int> BT(10000);
vector<int> Task, Time;
vector<pair<int, pair<int, int>>> V;
void Round_Robin(queue<pair<int, int>> Burst, int quan) {
  while (!Burst.empty()) {
    pair<int, int> a;
    a = Burst.front();
    Burst.pop();
    if (a.second <= quan) {
      t += a.second;
      TurnOver[a.first] = t;
      Time.push_back(t);
      Task.push_back(a.first);

    } else {
      t += quan;
      a.second -= quan;
      Time.push_back(t);
      Task.push_back(a.first);
      Burst.push(a);
    }
  }
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p >> b;
    V.push_back({p, {i, b}});
    BT[i] = b;
  }
  sort(V.begin(), V.end());
  queue<pair<int, int>> Burst;
  for (int i = 0; i < n; i++) {
    if ((V[i].first != V[i + 1].first)) {
      t += V[i].second.second;
      TurnOver[V[i].second.first] = t;
      Time.push_back(t);
      Task.push_back(V[i].second.first);
    } else {
      Burst.push({V[i].second.first, V[i].second.second});
      int k = i + 1;
      while (V[i].first == V[k].first) {
        Burst.push({V[k].second.first, V[k].second.second});
        k++;
      }
      i = --k;
      Round_Robin(Burst, q);
    }
  }
  cout << "TASK :  ";
  int avgT = 0, avgW = 0;
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl << "TURN :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] << " ";
    avgT += TurnOver[i];
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] - BT[i] << " ";
    avgW += TurnOver[i] - BT[i];
  }
  cout << endl;
  cout << "AVERAGE TURNOVER : " << (double)avgT / n << endl;
  cout << "AVG WAITING : " << (double)avgW / n << endl;
  cout << "THE GANDCHART: " << endl << 0;
  for (int i = 0; i < Time.size(); i++) {
    cout << "---P" << Task[i] << "---" << Time[i];
  }
}