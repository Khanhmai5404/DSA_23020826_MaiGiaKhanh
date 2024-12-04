#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        dfsHelper(startVertex, visited);
    }

    void dfsHelper(int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) dfsHelper(neighbor, visited);
        }
    }

    void display() {
        for (int v = 0; v < numVertices; v++) {
            cout << v << ": ";
            for (int neighbor : adjacencyList[v]) cout << neighbor << " ";
            cout << endl;
        }
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Danh sach ke cua do thi:\n";
    g.display();

    cout << "\n DFS TU DINH 0  : ";
    g.DFS(0);

    return 0;
}
