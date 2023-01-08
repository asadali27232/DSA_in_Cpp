#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100 // maximum number of nodes
#define INF INT_MAX // infinite distance

int n; // number of nodes
int dist[MAXN]; // array to store the distances from source
int graph[MAXN][MAXN]; // adjacency matrix to represent the graph
bool visited[MAXN]; // array to store whether a node has been visited or not

// priority queue to store nodes according to their distances from source
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int source) {
// set all distances to infinite and mark all nodes as unvisited
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

// distance from source to itself is 0
    dist[source] = 0;

// insert the source node into the priority queue
    pq.push({0, source});

    while (!pq.empty()) {
        // get the node with the minimum distance
        int u = pq.top().second;
        pq.pop();

        // if the node has already been visited, continue to the next node
        if (visited[u]) continue;

        // mark the node as visited
        visited[u] = true;

        // update the distances of the adjacent nodes
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }
}

int main() {
// input the number of nodes and the adjacency matrix
    cout << "Enter the number of nodes:";

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter Matrix Value:";
            cin >> graph[i][j];
        }
    }
// run Dijkstra's algorithm from the source node
    int source;
    cin >> source;
    dijkstra(source);

// print the distances from the source node
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}
