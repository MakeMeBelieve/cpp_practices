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

bool explore(const std::unordered_map<uint32_t, std::vector<uint32_t>>& graph, uint32_t vertex, 
std::unordered_map<uint32_t,bool>& visited)
{
    if(visited[vertex]) return false;
    visited[vertex] = true;
    
    for(const auto& it : graph.at(vertex))
    {
        explore(graph, it, visited);
    }
    
    return true;
}

uint32_t connectedComponentCounts(const std::unordered_map<uint32_t, std::vector<uint32_t>>& graph)
{
    uint32_t count = 0;
    std::unordered_map<uint32_t,bool> visited;
    
    for(const auto& it : graph)
    {
        if(explore(graph, it.first, visited)) count++;
    }
    
    return count;
}

int main()
{
    
    uint32_t count;
    
    count = connectedComponentCounts(graph);

    std::cout << count << std::endl;
    
    return 0;
}