#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Edge {
    int v, weight;
    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }
};

void primMST(int n, vector<vector<Edge>> &graph) {
    vector<bool> inMST(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; 
    pq.push({0, 0});
    int totalWeight = 0;
    vector<pair<int, int>> mst; 

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int u = current.v;
        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += current.weight;

        
        for (const Edge &neighbor : graph[u]) {
            if (!inMST[neighbor.v]) {
                pq.push(neighbor);
                mst.push_back({u, neighbor.v});
            }
        }
    }

    cout << "Cay bao trum toi thieu (Prim):" << endl;
    for (const auto &edge : mst)
        cout << edge.first << " -- " << edge.second << endl;
    cout << "Tong trong so: " << totalWeight << endl;
}