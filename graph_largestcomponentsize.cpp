#include <bits/stdc++.h>

const std::unordered_map<uint32_t, std::vector<uint32_t>> graph =
{
    {0, {8,1,5}},
    {1, {0}},
    {5, {0,8}},
    {8, {0,5}},
    {2, {3,4}},
    {3, {2,4}},
    {4, {3,2}}
};

uint32_t exploreSize(const std::unordered_map<uint32_t, std::vector<uint32_t>>& graph, 
uint32_t vertex, std::unordered_map<uint32_t, bool>& visited)
{
    if(visited[vertex]) return 0;
    visited[vertex] = true;
    
    uint32_t edges = 1;
    
    for(auto neighbor : graph.at(vertex))
    {
        edges += exploreSize(graph, neighbor, visited);
    }
    
    return edges;
}

uint32_t largestComponent(const std::unordered_map<uint32_t, std::vector<uint32_t>>& graph)
{
    std::unordered_map<uint32_t, bool> visited;
    uint32_t count = 0;
    
    for(auto it: graph)
    {
        uint32_t size = exploreSize(graph,it.first, visited);
        if(size > count) count = size;
    }
    
    return count;
}

int main()
{
    uint32_t largestSize = 0;
    
    largestSize = largestComponent(graph);
    
    std::cout << largestSize << std::endl;

    return 0;
}