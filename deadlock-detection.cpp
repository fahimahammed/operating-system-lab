#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a cycle exists in the graph starting from the current node
bool haveCycle(int cur, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[cur] = true;
    for (int x : graph[cur]) {
        if (!visited[x]) {
            return haveCycle(x, visited, graph);
        } else {
            return true;
        }
    }
    visited[cur] = false;

    return false;
}

int main() {
    freopen("deadlock.txt", "r", stdin);

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<bool> visited(numNodes + 1, false);
    vector<vector<int>> graph(numNodes + 1);

    // Reading the edges of the graph
    for (int i = 0; i < numEdges; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        graph[nodeA].push_back(nodeB);
    }

    // Checking for deadlock in the graph
    for (int i = 1; i < numNodes + 1; i++) {
        if (!visited[i]) {
            if (haveCycle(i, visited, graph)) {
                cout << endl << "Deadlock Found!" << endl;
                break;
            } else {
                cout << endl << "No Deadlock Found" << endl;
                break;
            }
        }
    }

    return 0;
}
