#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20
#define INF 9999

/* ---------- KRUSKAL ---------- */
struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unite(int x, int y) {
    parent[x] = y;
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskal(Edge edges[], int V, int E) {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + E, compare);

    cout << "\nTracing Table (Kruskal's Algorithm):\n";
    cout << "Step\tEdge(u,v)\tWeight\tAction\n";

    int count = 0, cost = 0, step = 1;

    for (int i = 0; i < E && count < V - 1; i++) {
        int x = find(edges[i].u);
        int y = find(edges[i].v);

        cout << step++ << "\t(" << edges[i].u << "," << edges[i].v << ")\t\t"
             << edges[i].w << "\t";

        if (x != y) {
            unite(x, y);
            cost += edges[i].w;
            count++;
            cout << "Selected\n";
        } else {
            cout << "Rejected\n";
        }
    }

    cout << "Total MST Cost (Kruskal) = " << cost << endl;
}

/* ---------- PRIM ---------- */
void prim(int graph[MAX][MAX], int V) {
    int selected[MAX] = {0};
    selected[0] = 1;

    int edges = 0, cost = 0, step = 1;

    cout << "\nTracing Table (Prim's Algorithm):\n";
    cout << "Step\tEdge(u,v)\tWeight\n";

    while (edges < V - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << step++ << "\t(" << x << "," << y << ")\t\t" << min << endl;

        selected[y] = 1;
        cost += min;
        edges++;
    }

    cout << "Total MST Cost (Prim) = " << cost << endl;
}

/* ---------- MAIN ---------- */
int main() {
    int V, E;
    Edge edges[MAX];
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INF;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        graph[edges[i].u][edges[i].v] = edges[i].w;
        graph[edges[i].v][edges[i].u] = edges[i].w;
    }

    kruskal(edges, V, E);
    prim(graph, V);

    return 0;
}

