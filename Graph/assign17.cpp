#include <iostream>
using namespace std;
class Graph
{
    int v;
    int e;
    int **adj;

public:
    void createGraph(int, int);
    void printGraph();
    void printadjnode(int);
    bool isisolated(int);
    ~Graph();
};
Graph::~Graph()
{
    for (int i = 0; i < v; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
}
void Graph::createGraph(int a, int b)
{
    v = a;
    e = b;
    adj = new int *[v];
    for (int i = 0; i < v; i++)
    {
        adj[i] = new int[v];
    }
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;
    cout << "enter connected vertices : " << endl;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}
void Graph::printGraph()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph ::printadjnode(int a)
{
    if (0 <= a < v)
    {
        for (int i = 0; i < v; i++)
        {
            if (adj[a][i] == 1)
                cout << "V" << i << endl;
        }
    }
}
bool Graph::isisolated(int a)
{
    bool Flag = true;
    if (0 <= a < v)
    {
        for (int i = 0; i < v; i++)
        {
            if (adj[a][i] == 1)
            {
                Flag = false;
                break;
            }
        }
    }
    return Flag;
}

int main()
{
    Graph Gr;
    Gr.createGraph(5, 7);
    Gr.printGraph();
    return 0;
}
