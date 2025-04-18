#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>  // reverse function

// Min-heap: (distance, node)
using pii = std::pair<int, char>;

typedef std::pair<char, int> node_t;
typedef std::unordered_map<char, std::vector<node_t>> graph_t;
typedef std::unordered_map<char, int> distances_t;
typedef std::unordered_map<char, char> parents_t;
typedef std::vector<char> path_t;

std::pair<distances_t, parents_t> dijkstra(graph_t &graph, char &start) {
    int int_max_val = 1 << 31 - 1;
    distances_t distances;
    parents_t parents;

    for (auto &[node, _] : graph) {
        distances[node] = int_max_val;
    }
    distances[start] = 0;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        auto [currDist, currNode] = minHeap.top();
        minHeap.pop();

        if (currDist > distances[currNode]) continue;

        for (auto &[neighbor, weight] : graph[currNode]) {
            int newDist = currDist + weight;
            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                parents[neighbor] = currNode;  // Save path
                minHeap.push({newDist, neighbor});
            }
        }
    }
    return { distances, parents };
}

// Function to reconstruct path from start to target
path_t reconstruct_path(const char &target, parents_t &parents) {
    path_t path;
    char current = target;

    while (parents.find(current) != parents.end()) {
        path.push_back(current);
        current = parents[current];
    }
    path.push_back(current);  // Add start node
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    graph_t graph = {
    { 'A', { {'B', 1}, {'C', 4} } },
    { 'B', { {'C', 2}, {'D', 5} } },
    { 'C', { {'D', 1} } },
    { 'D', {} }
    };

    char start_node = 'A';
    auto [distances, parents] = dijkstra(graph, start_node);
    for (auto &[node, distance] : distances) {
        std::cout << "Distance from " << start_node << " to " << node << " is " << distance << std::endl;
    }
    char end_node = 'C';
    auto shortest_path = reconstruct_path(end_node, parents);
    std::cout << "START";
    for (auto &node : shortest_path) {
        std::cout << " -> " << node;
    }
    std::cout << " -> END" << std::endl;
    return 0;
}
