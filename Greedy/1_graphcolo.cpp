#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);

        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

string color[] =
    {
        "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
        "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"};

void colorGraph(Graph const &graph, int n)
{
    unordered_map<int, int> result;

    for (int u = 0; u < n; u++)
    {
        set<int> assigned;

        for (int i : graph.adjList[u])
        {
            if (result[i])
            {
                assigned.insert(result[i]);
            }
        }

        int color = 1;

        for (auto &c : assigned)
        {
            if (color != c)
            {
                break;
            }
            color++;
        }

        result[u] = color;
    }

    for (int v = 0; v < n; v++)
    {
        cout << "The color assigned to vertex " << v << " is "
             << color[result[v]] << endl;
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}};

    int n = 6;

    Graph graph(edges, n);

    colorGraph(graph, n);

    return 0;
}