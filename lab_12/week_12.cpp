#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size();
    vector<int> distance(n, INF);
    vector<int> visited(n, 0);

    distance[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int r = pq.top().second;
        pq.pop();

        if (visited[r])
            continue;

        visited[r] = 1;

        for (int i = 0;i < n; ++i) {
            if (graph[r][i] != 0) {
                int weight = graph[r][i];

                if (distance[r] + weight < distance[i]) {
                    distance[i] = distance[r] + weight;
                    pq.push({distance[i],i});
                }
            }
        }
    }

    cout << "Shortest Distances from the Source:\n";
    for (int r = 0; r < n; ++r) {
        cout << "City " << startNode << " to City" << r << " : " << distance[r] << endl;
    }
}

int main() {
    vector<vector<int>> graph = { {0, 10, 0, 0, 15, 5},
                                  {10, 0, 10, 30, 0, 0},
                                  {0, 10, 0, 12, 5, 0},
                                  {0, 30, 12, 0, 0, 20},
                                  {15, 0, 5, 0, 0, 0},
                                  {5, 0, 0, 20, 0, 0}};

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    dijkstra(graph, startNode);

    return 0;
}