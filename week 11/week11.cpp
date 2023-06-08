#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

 
struct EdgeComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void prims(const vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();

    vector<bool> visited(numNodes, false);  
    vector<int> min_weight(numNodes, INT_MAX);    
    vector<int> parent(numNodes, -1);   

    priority_queue<pair<int, int>, vector<pair<int, int>>, EdgeComparator> pq;
    pq.push({startNode, 0});
    min_weight[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        visited[u] = true;

         
        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < min_weight[v]) {
                min_weight[v] = graph[u][v];
                parent[v] = u;
                pq.push({v, min_weight[v]});
            }
        }
    }

     
    cout << "Start node: " << startNode << endl;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < numNodes; i++) {
        if (parent[i] != -1) {
            cout << "Node " << parent[i] << " - Node " << i << ": Weight = " << graph[i][parent[i]] << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = { {0, 3, 0, 0, 0, 1},
                                  {3, 0, 2, 1, 10, 0},
                                  {0, 2, 0, 3, 0, 0},
                                  {0, 1, 3, 0, 5, 0},
                                  {0, 10, 0, 5, 0, 4},
                                  {1, 0, 0, 0, 4, 0}};

    int startNode = 0;
    prims(graph, startNode);

    return 0;
}
