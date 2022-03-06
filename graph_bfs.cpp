#include <bits/stdc++.h>

class Graph{
    uint32_t numVertices;
    std::list<uint32_t>* adjList;
    std::vector<bool>* visited;
    
    public:
    Graph(uint32_t vertices);
    ~Graph();
    void addEdge(uint32_t src, uint32_t dst);
    void BFS(uint32_t startVertex);
    void DFS(uint32_t startVertex);
    void clearVisited();
};


Graph::Graph(uint32_t vertices)
{
    numVertices = vertices;
    adjList = new std::list<uint32_t>[vertices];
    visited = new std::vector<bool>(vertices, false);
}

Graph::~Graph()
{
    delete[] adjList;
}

void Graph::addEdge(uint32_t src, uint32_t dst)
{
    if(src > numVertices || dst > numVertices) return;
    
    adjList[src].push_back(dst);
    adjList[dst].push_back(src);
}

void Graph::BFS(uint32_t startVertex)
{
    clearVisited();
    std::queue<uint32_t> queue;
    queue.push(startVertex);
    (*visited)[startVertex] = true;
    
    while(!queue.empty())
    {
        uint32_t vertex = queue.front();
        queue.pop();
        
        std::cout << "vertexBFS: " + std::to_string(vertex) << std::endl;
        
        for(auto it : adjList[vertex])
        {
            if(!(*visited)[it])
            {
                (*visited)[it] = true;
                queue.push(it);
            }
        }
    }
}


void Graph::clearVisited()
{
    for(auto it : *visited)
        it = false;
}

void Graph::DFS(uint32_t startVertex)
{
    std::cout << "vertexDFS: "  + std::to_string(startVertex) << std::endl;
    (*visited)[startVertex] = true;
    
    for(auto it : adjList[startVertex])
    {
        if(!(*visited)[it]) DFS(it);
    }
}


int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,3);
    
    g.BFS(2);
    
    g.clearVisited();
    g.DFS(2);
    
    return 0;
}
