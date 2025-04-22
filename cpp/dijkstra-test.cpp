#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

using pii = pair<int, string>;

// Modified Dijkstra that also returns parent map for path reconstruction
pair<unordered_map<string, int>, unordered_map<string, string>> dijkstra_with_paths(
    unordered_map<string, vector<pair<string, int>>> &graph,
    const string &start
) {
    unordered_map<string, int> distances;
    unordered_map<string, string> parents;

    for (auto &[node, _] : graph) {
        distances[node] = INT_MAX;
    }
    distances[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
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

    return {distances, parents};
}

// Function to reconstruct path from start to target
vector<string> reconstruct_path(
    const string &target,
    unordered_map<string, string> &parents
) {
    vector<string> path;
    string current = target;

    while (parents.find(current) != parents.end()) {
        path.push_back(current);
        current = parents[current];
    }
    path.push_back(current);  // Add start node
    reverse(path.begin(), path.end());
    return path;
}