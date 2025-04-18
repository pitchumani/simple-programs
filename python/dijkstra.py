import heapq

def dijkstra(graph, start):
    # Priority queue: (distance_from_start, node)
    min_heap = [(0, start)]
    # Distance from start to each node (default is infinity)
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    visited = set()

    while min_heap:
        curr_dist, curr_node = heapq.heappop(min_heap)

        if curr_node in visited:
            continue
        visited.add(curr_node)

        for neighbor, weight in graph[curr_node]:
            distance = curr_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(min_heap, (distance, neighbor))

    return distances

graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', 2), ('D', 5)],
    'C': [('D', 1)],
    'D': []
}

start_node = 'A'
distances = dijkstra(graph, start_node)
print(distances)

